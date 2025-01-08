#include "pch.h"
#include "Task.h"
using namespace std;


TEST(TestTask, BadFileSignature) {
	string fileName = "bfs.bmp";
	bool res = CheckBMP(fileName);
	EXPECT_FALSE(res);
}

TEST(TestTask, BadFileHeaderSize) {
	string fileName = "bfhs.bmp";
	bool res = CheckBMP(fileName);
	EXPECT_FALSE(res);
}

TEST(TestTask, BadFileLength) {
	string fileName = "bfl.bmp";
	bool res = CheckBMP(fileName);
	EXPECT_FALSE(res);
}

TEST(TestTask, GoodFile) {
	string fileName = "gf.bmp";
	bool res = CheckBMP(fileName);
	EXPECT_TRUE(res);
}