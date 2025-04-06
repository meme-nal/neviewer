#ifndef EDF_H
#define EDF_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
* EDF+ FILE CONSISTS OF HEADER AND DATA RECORDS
* HEADER CONSISTS OF TWO PARTS
* FIRST IS ALWAYS 256 BYTES
* SECOND IS NUMBER OF SIGLANS (ns) * 256 BYTES 
* 
*/


/* THE FIRST PART OF EDF+ HEADER IS 256 BYTES */
struct EDFHeader {
  char version[8]; // MUST BE 0
  char patientID[80]; // 
  char recordingID[80];
  char startDate[8];
  char startTime[8];
  char numBytesHeader[8];
  char reserved[44];
  char numRecords[8]; // -1 IF UNKNOWN 
  char recordDuration[8]; // IN SECONDS BETWEEN 0 AND 1
  char numSignals[4];
};

/* THE LAST PART OF EDF+ HEADER IS ns * 256 */
struct EDFHeaderLast {
  EDFHeaderLast(const int ns) {
    labels.resize(ns * 16);
    transducerTypes.resize(ns * 80);
    physicalDimension.resize(ns * 8);
    physicalMinimum.resize(ns * 8);
    physicalMaximum.resize(ns * 8);
    digitalMinimum.resize(ns * 8);
    digitalMaximum.resize(ns * 8);
    prefiltering.resize(ns * 80);
    numSamplesInEachDataRecord.resize(ns * 8);
    reserved.resize(ns * 32);
  }

  std::vector<char> labels; // LIST OF CHANNEL NAMES
  std::vector<char> transducerTypes;
  std::vector<char> physicalDimension;
  std::vector<char> physicalMinimum;
  std::vector<char> physicalMaximum;
  std::vector<char> digitalMinimum;
  std::vector<char> digitalMaximum;
  std::vector<char> prefiltering; // HIGH PASS AND LOW PASS FILTERS INFORMATION FOR EACH CHANNEL
  std::vector<char> numSamplesInEachDataRecord;
  std::vector<char> reserved;
};

class EDF {
public:
  EDF(const std::string& filepath);

private:
  int version;
  std::string patientId;
  std::string recordingId;
  std::string startDate;
  std::string startTime;
  int numBytesHeader;
  std::string reserved;
  int numRecords;
  float recordDuration;
  int numSignals;

  std::vector<std::string> labels;
  std::vector<std::string> transducerTypes;
  std::vector<std::string> physicalDimensions;
  std::vector<float> physicalMinimums;
  std::vector<float> physicalMaximums;
  std::vector<float> digitalMinimums;
  std::vector<float> digitalMaximums;
  std::vector<std::string> prefilterings;
  std::vector<int> numSamples;  
  std::vector<std::string> reservedLast;
};

#endif // EDF_H