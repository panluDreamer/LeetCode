#ifndef PFMUTILS_H
#define PFMUTILS_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class PFM {

public:
	 char head[2];
	 int width, height;
	 char temp;
	 char buf[100];
	 void load_pfm(string img_path) {
		fstream file;
		file.open(img_path.c_str(), ios::in | ios::binary);
		if (file.good()) {
			cout << "open success" << endl;
			cout << file.tellg() << endl;
			file.read(head, sizeof(char)*2);
			cout << file.tellg() << endl;
			//file.seekg(1, ios::cur);
			file.read((char*)(&temp), sizeof(char));
			cout << file.tellg() << endl;
			file.read((char *)(&width), 4);
			//cout << file.tellg() << endl;
			//file.seekg(1, ios::cur);
			//file.read((char*)(&height),sizeof(int));
			//file.read(buf, 100);
			cout << file.tellg() << endl;
			file.close();
			cout << "head = " << endl;
			cout << head[0]<<head[1] << endl;
			cout << "temp = " << temp;
			cout << "width = " << hex<<width << endl;
			//cout << "buf=" << endl;
			//for (int i = 0; i < 5;i++) {
			//	cout << buf[i];
			//}
		}
		else {
			cout << "failed open" << endl;
		}
	}
};



#endif