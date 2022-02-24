SOURCE_DIR = ../
CC = g++
CFLAGS = -g -Wall -std=c++11 -c
IFLAGS =  -I$(SOURCE_DIR)
LFLAGS = -o

TestHFPage: TestHFPage.o FixedStringValue.o IntegerValue.o Tuple.o HFPage.o Page.o
	$(CC) TestHFPage.o FixedStringValue.o IntegerValue.o Tuple.o HFPage.o Page.o $(LFLAGS) TestHFPage

TestTuple: TestTuple.o FixedStringValue.o IntegerValue.o Tuple.o
	$(CC) TestTuple.o FixedStringValue.o IntegerValue.o Tuple.o $(LFLAGS) TestTuple

TestValue: TestValue.o FixedStringValue.o IntegerValue.o
	$(CC) TestValue.o FixedStringValue.o IntegerValue.o $(LFLAGS) TestValue

HFPage.o: $(SOURCE_DIR)HFPage.cpp  $(SOURCE_DIR)HFPage.h $(SOURCE_DIR)RecordId.h
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)HFPage.cpp

Page.o: $(SOURCE_DIR)Page.cpp  $(SOURCE_DIR)Page.h $(SOURCE_DIR)Page.h
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)Page.cpp


StringValue.o: $(SOURCE_DIR)StringValue.cpp  $(SOURCE_DIR)StringValue.h
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)StringValue.cpp

FixedStringValue.o: $(SOURCE_DIR)FixedStringValue.cpp  $(SOURCE_DIR)FixedStringValue.h
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)FixedStringValue.cpp

IntegerValue.o : $(SOURCE_DIR)IntegerValue.cpp  $(SOURCE_DIR)IntegerValue.h
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)IntegerValue.cpp

Tuple.o : $(SOURCE_DIR)Tuple.cpp  $(SOURCE_DIR)Tuple.h
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)Tuple.cpp

TestValue.o: $(SOURCE_DIR)TestValue.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)TestValue.cpp

TestTuple.o: $(SOURCE_DIR)TestTuple.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)TestTuple.cpp

TestHFPage.o: $(SOURCE_DIR)TestHFPage.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCE_DIR)TestHFPage.cpp

clean :
	rm *.o TestValue TestTuple  TestHFPage