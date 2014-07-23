#include <iostream>

#include <string>
#include <algorithm>

typedef int(*UnaryOperator)(int);

static int minusOne(int x);
static std::string transformFor(const std::string &str, UnaryOperator op);

int main(int argc, char *argv[]) {
	UnaryOperator ops[] = {
		tolower,
		toupper,
		minusOne,
	};

	int n = sizeof(ops) / sizeof(ops[0]);

	for (int i = 1; i < argc; i++) {
		if (i > 1) {
			std::cout << std::endl;
		}

		std::string str = argv[i];
		std::cout << str;

		for (int j = 0; j < n; j++) {
			std::string t = transformFor(str, ops[j]);
			std::cout << "\t->\t" << t << std::endl;
		}
	}

	return 0;
}

int minusOne(int x) {
	return x - 1;
}

std::string transformFor(const std::string &str, UnaryOperator op) {
	std::string t = str;

	transform(str.begin(), str.end(), t.begin(), op);

	return t;
}