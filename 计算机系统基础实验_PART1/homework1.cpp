#include<iostream>
#include<string>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
#define N 5
struct student {
	char name[8];
	short age;//2
	float score;//4
	char remark[200];
}old_s[N], new_s[N];

char message[1500];
int m_id;
char* pack_student_bytebybyte_single(student* s, char* buf) {
	char* begin = buf, * end = buf;
	char* it = (char*)&(s);
	for (int i = 0; i < strlen(s->name) + 1; i++) {
		*end = s->name[i];
		++end;
	}
	it = (char*)&(s->age);
	for (int i = 1; i <= 2; ++i) {
		*end = *it;
		++end;
		++it;
	}
	it = (char*)&(s->score);
	for (int i = 1; i <= 4; ++i) {
		*end = *it;
		++end;
		++it;
	}
	for (int i = 0; i < strlen(s->remark) + 1; ++i) {
		*end = s->remark[i];
		++end;
	}
	return end;
}
int pack_student_bytebybyte(student* s, int sno, char* buf) {
	char* begin = buf;
	for (int i = 1; i <= sno; ++i) {
		buf = pack_student_bytebybyte_single(s, buf);
		s++;
	}
	return buf - begin;
}

char* pack_student_whole_single(student* s, char* buf) {
	char* end = buf;
	strcpy(buf, s->name);
	buf += strlen(s->name) + 1;
    // cout<<buf-message<<endl;
	short* tmp_s = (short*)buf;
	*tmp_s = s->age;
	buf += sizeof(short);
	float* tmp_f = (float*)buf;
	*tmp_f = s->score;
	buf += sizeof(float);
    // cout<<buf-message<<endl;
	strcpy(buf, s->remark);
	buf += strlen(s->remark) + 1;
	return buf;
}
int pack_student_whole(student* s, int sno, char* buf) {
	char* begin = buf;
	for (int i = 1; i <= sno; ++i) {
		buf = pack_student_whole_single(s, buf);
		s++;
	}
	return buf - begin;
}

char* restore_student_single(char* buf, student* s) {
	char* tmp = buf;
	strcpy(s->name, buf);
	buf += strlen(buf) + 1;
	s->age = *((short*)buf);
	buf += 2;
	s->score = *((float*)buf);
	buf += 4;
	strcpy(s->remark, buf);
	buf += strlen(buf) + 1;
	return buf;
}
int restore_student(char* buf, int len, student* s) {
	char* begin = buf;
	int cnt = 0;
	while (buf - begin <= len) {
		buf = restore_student_single(buf, s);
		s++;
		++cnt;
	}
	return cnt;
}
int main() {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 5; ++i) {
		cin >> old_s[i].name >> old_s[i].age >> old_s[i].score >> old_s[i].remark;
	}
	char* buf = message;
	student* s = old_s;
	buf += pack_student_bytebybyte(s, 2, buf);
	s += 2;
    cout<<buf-message<<endl;
	buf += pack_student_whole(s, 3, buf);
	int len = buf - message;
	int num = restore_student(message, len, new_s);
	for (int i = 0; i < 5; ++i) {
		cout << new_s[i].name << " " << new_s[i].age << " " << new_s[i].score << " " << new_s[i].remark << endl;
	}
	return 0;

}