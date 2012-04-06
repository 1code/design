#ifndef _STATE_H_
#define _STATE_H_

class TCPConn;

class TCPState {
	public:
		TCPState();
		virtual ~TCPState();
		virtual void ActiveOpen(TCPConn* con);
		virtual void PassiveOpen(TCPConn* con);
		virtual void SendRequest(TCPConn* con);
		virtual void Transmit(TCPConn* con);
		virtual void Close(TCPConn* con);
	protected:
		bool ChangeState(TCPConn * con, TCPState* st);
};

class TCPEstablished : public TCPState {
	public:
		TCPEstablished();
		virtual ~TCPEstablished();
		virtual void Transmit(TCPConn* con);
		virtual void Close(TCPConn* con);
};

class TCPListenning : public TCPState {
	public:
		TCPListenning ();
		virtual ~TCPListenning ();
		virtual void SendRequest(TCPConn* con);
};

class TCPClosed : public TCPState {
	public:
		TCPClosed ();
		virtual ~TCPClosed ();
		virtual void ActiveOpen(TCPConn* con); 
		virtual void PassiveOpen(TCPConn* con); 	
};


#endif
