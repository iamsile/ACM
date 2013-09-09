#include <iostream>
using namespace std;

int main()
{
    double a[4];
    while (cin >> a[0] >> a[1] >> a[2]) {
        if (!a[0]&&!a[1]&&!a[2])
            return 0;
        sort(a, a+3);
        if (a[0]>=0.25&&a[1]>=90&&a[2]>=125) {
            if (a[0]<=7&&a[1]<=155&&a[2]<=290)
                cout << "letter\n";
            else {
                if (a[0]<=50&&a[1]<=300&&a[2]<=380)
                    cout << "packet\n";
                else if (2*a[0]+2*a[1]+a[2]<=2100)
                    cout << "parcel\n";
                else
                    cout << "not mailable\n";
            }
        }
        else cout << "not mailable\n";
    }
    return 0;
}
/*
 Problem description
 Other than postcards, the post office department of some country recognizes three classes of mailable items: letters, packets, and parcels. The three dimensions of a mailable item are called length, height and thickness, with length being the largest and thickness the smallest of the three dimensions.
 
 A letter's length must be at least 125mm but not more than 290mm, its height at least 90mm but not more than 155mm, and its thickness at least 0.25mm but not more than 7mm. (The unit millimeter is abbreviated by mm.)
 
 All three of a packet's dimensions must be greater than or equal to the corresponding minimum dimension for a letter, and at least one of its dimensions must exceed the corresponding maximum for a letter. Furthermore, a packet's length must be no more than 380mm, its height no more than 300mm, and its thickness no more than 50mm.
 
 All three of a parcel's dimensions must be greater than or equal to the corresponding minimum dimension for a letter, and at least one of its dimensions must exceed the corresponding maximum for a packet. Furthermore, the parcel's combined length and girth may not exceed 2100mm. (The girth is the full perimeter measured around the parcel, perpendicular to the length.)
 
 
 
 Input
 The input will contain data for a number of problem instances. For each problem instance, the input will consist of the three dimensions (measured in mm) of an item, in any order. The length and width will be positive integers. The thickness will be either a positive integer or a positive floating point number. The input will be terminated by a line containing three zeros.
 
 
 
 Output
 For each problem instance, your program will classify the item as letter, packet, parcel or not mailable. This verdict will be displayed at the beginning of a new line, in lower case letters.
 
 
 
 Sample Input
 100 120 100
 0.5 100 200
 100 10 200
 200 75 100
 0 0 0 
 Sample Output
 not mailable
 letter
 packet
 parcel
*/