// WAVE file header format
struct HEADER {
    unsigned char strRiff[4]; // 4 bytes (string).
    unsigned int sizeOfFile; // 4 bytes (int). Size of file in bytes.
    unsigned char strWave[4]; // 4 bytes (string). WAVE string.
    unsigned char strFormatChunkMarker[4]; // 4 bytes (string). Format string with trailing null character.
    unsigned int lengthOfFormat; // 4 bytes (int). Fength of format data.
    unsigned int typeOfFormat; // 4 bytes (int). {1: PCM, 3: IEEE float, 6: 8bit A law, 7: 8bit mu law}.
    unsigned int noOfChannels; // 4 bytes (int). Number of channels.
    unsigned int noOfBitsPerSample; // 4 bytes (int). {8: 8bits, 16: 16bits, ...}.
    unsigned int rateOfsamples; // 4 bytes (int). Sampling rate in blocks per second.
    unsigned int rateOfBytes; // 4 bytes (int). rateOfsamples * noOfChannels * (noOfBitsPerSample / 8)
    unsigned int alignmentOfBlocks; // 4 bytes (int). noOfChannels * (noOfBitsPerSample / 8)
    unsigned char strDataChunkHeader[4]; // 4 bytes (string). DATA string or FLLR string.
    unsigned int sizeOfData; // 4 bytes (int). rateOfsamples * noOfChannels * (noOfBitsPerSample / 8) - size of the next chunk to be read.
};