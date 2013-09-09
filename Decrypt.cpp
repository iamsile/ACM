#include <stdio.h>
int main() {
    int n = 10;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ;
            }
        }
    }
    puts("Please submit me, then you will get AC :-)");
    puts("The key is RobaHouGong3000DuoWanOrz");
    return 0;
}
//key:#include<stdio.h> int main()
/*
 Problem Description
 Licstar has a tool which can encrypt any text file by simple XOR encryption. The main procedure for this tool is as below.
 
 for(int i = 0; i < contentLength; i += keyLength) {
 for(int j = 0; j < keyLength && i + j < contentLength; j++) {
 fprintf(f, "%.2x", content[i + j] ^ key[j]);
 }
 }
 
 One day, Doraemonok found the tool and encrypt a source code "source.cpp" by it. If you submit original "source.cpp" you can get Accepted, but unfortunately, you only have the encypted "source.cpp" and you do not know the key. The length of key is no more than 30.
 
 The encrypted "source.cpp" in hex is as below.
 
 71060c02241a11224f52144754595f6a1d515d08003b521733060c49614f0e4d4f4e4713595e44641b4f6a415f7f4970724f42412e0007674707094710591079555f6c41076f4e5a3c54420863445c671464471310101064554f310e1c6f5a133c1b420b68525577544e0d130c105e7f55057c4a476f0970724f4241684f55674f4e4713565f42645d0639154e245247725f5941234f4967015547581b1b19640e6577414e6f525a724f4241684f55674f4e5c3910101064554f77414e6f525a2f654241684f55674f4e1a3910101064086577414e6f5d55060707412b0011224f0c02555f4255641c1c77141d2a1e1f211c4e412701193e4f08084110595e27070a36120721155a26070741240a1b201b06475c5610442c1c1c7702012b1754584f4241681f00331c4645635c555137104f24140c221b0e7202074d681b1d22014e1e5c4510472d190377060b3b523b114f584c614d5c7c654e47131040453006477535062a5211371642083b4f27280d0f2f5c45775f2a125c67515e0b0715050e0c2e3a15576e5464471310101f6b210732410f3a06123d1d1141270955330707141340425f26190a3a41546f1e13311c16003a4f14290b4e035c425155291a01380a646f525a721d07153d1d1b675f556d4e3a3a
 Output
 Please submit the original "source.cpp"
*/