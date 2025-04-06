#include "edf.h"

EDF::EDF(const std::string& filepath) {
  std::ifstream edfFile(filepath, std::ios::binary);
  if (!edfFile.is_open()) {
    std::cerr << "Failed to open EDF file.\n";
  }

  // READING FIRST PART OF EDF
  EDFHeader header;
  edfFile.read(reinterpret_cast<char*>(&header), sizeof(header));

  // GO TO LAST PART
  edfFile.seekg(256);

  // READING LAST PART OF EDF
  int ns = std::atoi(header.numSignals);
  EDFHeaderLast headerLast(ns);

  edfFile.read(reinterpret_cast<char*>(headerLast.labels.data()), ns * 16);
  edfFile.read(reinterpret_cast<char*>(headerLast.transducerTypes.data()), ns * 80);
  edfFile.read(reinterpret_cast<char*>(headerLast.physicalDimension.data()), ns * 8);
  edfFile.read(reinterpret_cast<char*>(headerLast.physicalMinimum.data()), ns * 8);
  edfFile.read(reinterpret_cast<char*>(headerLast.physicalMaximum.data()), ns * 8);
  edfFile.read(reinterpret_cast<char*>(headerLast.digitalMinimum.data()), ns * 8);
  edfFile.read(reinterpret_cast<char*>(headerLast.digitalMaximum.data()), ns * 8);
  edfFile.read(reinterpret_cast<char*>(headerLast.prefiltering.data()), ns * 80);
  edfFile.read(reinterpret_cast<char*>(headerLast.numSamplesInEachDataRecord.data()), ns * 8);
  edfFile.read(reinterpret_cast<char*>(headerLast.reserved.data()), ns * 32);

  
}