Minitalk is a 42 project designed to explore Inter-Process Communication (IPC) in Unix-based systems using signals (SIGUSR1 and SIGUSR2). The project consists of a server and a client, where the client communicates with the server by sending text messages encoded as signals.

🔹 How It Works
🔹 Server (server):

Displays its PID (Process ID) upon startup.
Waits for signals (SIGUSR1 and SIGUSR2) from the client.
Reconstructs characters from received signals and prints the message to the terminal.
🔹 Client (client):

Sends a text message to the server’s PID.
Converts each character into a sequence of binary signals (bits) and transmits them using kill().
Ensures proper sequencing of the signals to prevent data loss.
🔹 Key Functions Used
🔹 getpid() → Retrieves the server’s PID.
🔹 kill(pid, signal) → Sends SIGUSR1 or SIGUSR2 signals to the server.
🔹 sigaction() → Sets up the signal handler.
🔹 pause() → Makes the server wait until it receives a signal.
🔹 usleep() → Adds a slight delay to ensure correct signal order.

🔹 How to Use
1️⃣ Start the Server:
sh
Copy
Edit
./server
📌 Expected Output:

arduino
Copy
Edit
Server PID: 12345
2️⃣ Run the Client to Send a Message:
sh
Copy
Edit
./client 12345 "Hello, World!"
📌 Expected Output on the Server Side:

Copy
Edit
Hello, World!
🔹 Why is Minitalk Important?
✅ Learn how to handle signals in Unix.
✅ Understand how text is converted into binary (bits).
✅ Gain hands-on experience with Inter-Process Communication (IPC).
✅ Work with system functions like sigaction, kill, pause, and getpid effectively.

🚀 A fun project that deepens your understanding of Unix system programming!
