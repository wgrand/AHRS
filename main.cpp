#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "filter/ComplementaryFilter.h"
#include "model/Vector.h"
#include "model/Quaternion.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;
using std::cout;
using std::endl;

int main()
{

    ComplementaryFilter *filter = new ComplementaryFilter();

    // Load samples    
    ifstream infile("data/ios/2023-04-05_07_57_06_my_iOS_device.csv");
    string line;
    bool first_line = true;
    float t = -1;
    float t0 = -1;
    Quaternion q = Quaternion();

    ofstream outfile("data/ios/deviceMotionSamplesRotated.csv");
    outfile << "t,x,y,z" << endl;

    while(getline(infile, line)) { 
        if(first_line) { 
            first_line = false;
            continue;
        }
        vector<float> fields;
        stringstream ss(line);
        string field;
        while (getline(ss, field, ',')) {
            try {
                float f = stof(field);
                fields.push_back(f);
            } catch (...) {
                fields.push_back(0);
            }
        }

        float dt = 0;
        if(t == -1) {
            t0 = fields[20];
            t = 0;
            continue;
        } else { 
            dt = (fields[20] - t0) - t;
            t = fields[20] - t0;
        }

        Vector acc = {fields[21], fields[22], fields[23]};
        Vector gyr = {fields[25], fields[26], fields[27]};
        Vector mag = {fields[29], fields[30], fields[31]};

        // Get new attitude quaternion
        q = filter->Update(q, acc, gyr, mag, dt, "NED");

        // Rotate acceleration vector by attitude quaternion
        Vector a = acc*q;

        // Write samples to CSV
        outfile << t << "," << a.x << "," << a.y << "," << a.z << endl;
        cout << t << "," << a.x << "," << a.y << "," << a.z << endl;

    }

    outfile.close();
    infile.close();

    delete filter;

    return 0;

}