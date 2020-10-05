#include "Parser.h"


Parser::Parser() {
	rounds = 1;
	typeP1 = 0;
	typeP2 = 0;
	p1name = "Player1";
	p2name = "Player2";
	info = "\nList of commands:\n1. --first, -f - set name of first player \n2. --second, -s - set name of second player\n3. --count, -c - set number of rounds";
}

int Parser::doWork(int argc, char* argv[]) { //return 1 if we need to close programm
	string arg = "";
	for (int i = 1; i < argc; i++) {
		arg = argv[i];
		if (arg == "-h" || arg == "--help") {
			cout << info;
			return 1;
		}

		if (arg == "-f" || arg == "--first") {
			if (i < argc - 1) {
				typeP1 = atoi(argv[i + 1]);
				i++;
			}
			else return 1;
		}

		if (arg == "-s" || arg == "--second") {
			if (i < argc - 1) {
				typeP2 = atoi(argv[i + 1]);
				i++;
			}
			else return 1;
		}

		if (arg == "-c" || arg == "--count") {
			if (i < argc - 1) {
				rounds = atoi(argv[i + 1]);
				i++;
			}
			else return 1;
		}
	}
	return 0;
}