 
#include "application.h"
 

#include <cstdio>

int MOTION=D5;
int BUZZ=A0;

int toInt(String string) {
    int i;
	sscanf(string.c_str(), "%d", &i);
	return i;
}

int buzz(String level) {
    return buzzLevel(toInt(level));
}

int buzzLevel(int level) {
	analogWrite(BUZZ,level);
	Spark.publish("tb/motion/buzz"+level);
	return 0;
}

void setup() {
	Spark.publish("tb/motion/setupbuzz1");
	pinMode(MOTION,INPUT_PULLDOWN);
	pinMode(A0,OUTPUT);
	Spark.function("buzz",buzz);
}

void loop() {
	int read = digitalRead(MOTION);
	if(read == HIGH) {
		buzzLevel(100);
	} else {
		buzzLevel(0);
	}
	delay(2);
}



