#include <iostream>
#include <fstream>

using namespace std;

void forming_logs(const u_char *data_buffer, const u_int32_t length, const char *filename) {
    ofstream os(filename, ios::app);
	if (!os) {
    	cout << "Cannot open the file to output. \n";
  	}

	u_char item[9] = {
		'.', '.', '.', 
		'.', 'u', 's',
		'e', 'r', 'n'
	};

	u_char byte;
	u_int32_t i, j, b;
	for(i=0;i<length;++i) {
		byte = data_buffer[i];
		if(((i%16)==15)||(i==length-1)) {
			for(j=0;j<15-(i%16);++j) 
				for(j=(i-(i%16));j<=i;++j) { //вывод отображаемых символов
					int count = 0;
					for(b=0; b<9; ++b) {
						if(data_buffer[j+b]==item[b]) {
							++count;
						}
						if(count == 9) {
							byte = data_buffer[j+b+6];
							while (byte!='&') { //username
								os << (u_char)byte; 
								++byte;
							}
							byte += 10;
							while (byte!='&') { // pass
								os << (u_char)byte; 
								++byte;
						}
							
						}
					}
				}
		}
	}
	os << "\n";
    os.close();
}
