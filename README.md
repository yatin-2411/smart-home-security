# smart-home-security
Cisco Packet Tracer Setup
Network Topology:

Start by creating a new Packet Tracer project.
Place devices on the workspace: PCs, a router (optional for internet connectivity simulation), and connecting them with appropriate connections (Ethernet cables).
Device Configuration:

PCs: Configure PCs to act as endpoints for receiving alert messages. PCs will run a simple HTTP server to accept incoming alerts.

Double-click on a PC, go to Desktop tab, and select Web Browser.
This will enable HTTP service on the PC.
Router (if needed): Connect PCs via a router for internet simulation. Configure router interfaces and routing protocols if necessary.

Assign IP Addresses:

Assign IP addresses to each PC and router interface within the same subnet for communication.
For example:
PC1: IP Address - 192.168.1.2/24
PC2: IP Address - 192.168.1.3/24
Router Interface: IP Address - 192.168.1.1/24
HTTP Server Configuration on PCs:

On each PC intended to receive alerts:
Go to Desktop > Web Browser.
Enter a suitable port (e.g., 80) and set up a basic HTTP server to listen for incoming requests.
Use a scripting language (e.g., Python's http.server module) or web server software (e.g., XAMPP) to handle HTTP POST requests.
