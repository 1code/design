#ifndef _CONTEXT_H_
#define _CONTEXT_H_

class TCPState;

class TCPConn {
	public:
		TCPConn();
		~TCPConn();
		void ActiveOpen();
		void PassiveOpen();
		void Transmit();
		void SendRequest();
		void Close();
	private:
		friend class TCPState;
		bool ChangeState(TCPState* state);
		TCPState* _state;
};

#endif
