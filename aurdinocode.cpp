#include <Ethernet.h>  // Include Ethernet library for Arduino Ethernet shield

// Define the MAC and IP address of the Arduino Uno
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 10); // IP address of Arduino

// Define the IP address and port of the PC running HTTP server in Packet Tracer
IPAddress server(192, 168, 1, 2); // IP address of PC1
const int serverPort = 80;       // Port number for HTTP server

EthernetClient client;

void setup() {
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  delay(1000);  // Allow time for Ethernet shield to initialize
}

void loop() {
  // Read sensor inputs and detect unauthorized entry
  int motionDetected = digitalRead(motionSensorPin);
  int doorOpened = digitalRead(doorSensorPin);

  if (motionDetected == HIGH || doorOpened == HIGH) {
    triggerAlert();
    delay(5000); // Delay to prevent continuous alerts
  }
}

void triggerAlert() {
  if (client.connect(server, serverPort)) {
    Serial.println("Connected to server");
    
    // Send HTTP POST request
    client.println("POST /alert HTTP/1.1");
    client.println("Host: 192.168.1.2"); // Replace with PC1's IP address
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(strlen("Unauthorized entry detected!"));
    client.println();
    client.println("Unauthorized entry detected!");
    
    delay(100); // Allow time for server to process request
    client.stop(); // Disconnect from server
    Serial.println("Alert sent successfully");
  } else {
    Serial.println("Connection failed");
  }
}
