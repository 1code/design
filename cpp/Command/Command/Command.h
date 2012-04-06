//Command.h

#ifndef _COMMAND_H_
#define _COMMAND_H_

using namespace std;

class Document;

class Command {
	public:
		Command(Document *doc);
		virtual ~Command();
		virtual void Excute() = 0;
	protected:
		Document* _doc;
};

class OpenCommand: public Command {
	public:
		OpenCommand(Document* doc);
		~OpenCommand();
		void Excute();
};

class PasteCommand: public Command {
	public:
		PasteCommand(Document* doc);
		~PasteCommand();
		void Excute();
};

#endif //~_COMMAND_H_
