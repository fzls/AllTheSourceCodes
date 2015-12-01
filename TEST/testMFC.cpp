void foo() {
	std::cout << "enter foo" << std::endl;
}
testMFC::testMFC(int d): data{d} {
	std::cout << "enter testMFC " << d << std::endl;
}
testMFC::~testMFC() {
	std::cout << "enter ~testMFC" << std::endl;
}
