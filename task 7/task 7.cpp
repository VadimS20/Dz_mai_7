#include "task 7.h"

using namespace std;

tree check(125);
mutex m;

void generate() {
	while(1) {
		m.lock();
		check.addData(rand());
		m.unlock();
	}
}

void show() {
	int i = 1;
	while(1) {
		m.lock();
		check.print();
		cout << "print №"<<i<<"\n";
		m.unlock();
		i++;
	}
}

int main()
{
	std::thread a (generate);
	std::thread b (show);

	a.join();
	b.join();

}