#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;

int main()
{
    srand(time(NULL));  // seed the random number generator




    int count = 0;
    string array[5000][3];
    ifstream file("myfile.csv");
    float array2[5000][2]{ 0 };





    cout << "id\tdist\tspeed\n";
    if (file.is_open())
    {
        int i = 0;

        cout << "Successfully open file" << endl;

        string id, dist, speed;
        getline(file, id, ',');
        getline(file, dist, ',');
        getline(file, speed, '\n');
        while (file.good())
        {
            getline(file, id, ',');
            getline(file, dist, ',');
            getline(file, speed, '\n');
            //cout << id << "\t" << dist << "\t" << speed << endl;
            for (int i = 0; i < 4; i++)   //this loop is to storing valaues in the string array
            {

                if (i == 0) {

                    array[count][i] = id;
                }
                else if (i == 1)
                {
                    array[count][i] = dist;
                }
                else if (i == 2)
                {
                    array[count][i] = speed;
                }
                /*else
                    array[count][i] = " ";*/
            }

            for (int j = 0; j < 2; j++) //this is for storing value in float array
            {
                if (j == 0)
                {
                    array2[count][j] = stold(dist);
                }
                else if (j == 1)
                {
                    array2[count][j] = stold(speed);
                }
            }
            count++;

        }
    }
    count -= 1;
    cout << count << endl;
    cout << "id\tdist\tspeed\n";

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }


    //for (int i = 0; i < count; i++)
    //{
    //    for (int j = 0; j < 2; j++)
    //    {
    //        cout << array2[i][j] << "\t";
    //    }
    //    cout << endl;
    //}

    int r1 = (rand() % 4000) + 2;//for genrating randum number 
    int r2 = (rand() % 4000) + 2;
    int r3 = (rand() % 4000) + 2;
    int r4 = (rand() % 4000) + 2;
    cout << "number 1\tnumber 2\tnumber 3\tnumber 4\t\n";
    cout << r1 << "\t\t" << r2 << "\t\t" << r3 << "\t\t" << r4 << "\t\t\n";

    double c1_dist = array2[r1 - 2][0]; //assigning value of form randum index to speed and dist
    double c2_dist = array2[r2 - 2][0];
    double c3_dist = array2[r3 - 2][0];
    double c4_dist = array2[r4 - 2][0];
    double c1_speed = array2[r1 - 2][1];
    double c2_speed = array2[r2 - 2][1];
    double c3_speed = array2[r3 - 2][1];
    double c4_speed = array2[r4 - 2][1];
    float c1[5000]{ 0 };
    float c2[5000]{ 0 };
    float c3[5000]{ 0 };
    float c4[5000]{ 0 };
    double k_1[4000][2]{ 0 }; //for aassigning the value of speed and dist to its near centroid
    double k_2[4000][2]{ 0 };
    double k_3[4000][2]{ 0 };
    double k_4[4000][2]{ 0 };
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;//size of all centroid array
    double c_2_1_dist = 0;
    double c_2_2_dist = 0;
    double c_2_3_dist = 0;
    double c_2_4_dist = 0;
    double c_2_1_speed = 0;
    double c_2_2_speed = 0;
    double c_2_3_speed = 0;
    double c_2_4_speed = 0;

    //int index_c1[4500]{ 0 };
  /*  int index_c2[4500]{ 0 };
    int index_c3[4500]{ 0 };
    int index_c4[4500]{ 0 };*/

    int center_array[4500]{ 0 };


    double sum1 = 0;
    double sum2 = 0;
    float dif = 0;
kmean:


    /* for (int i = 0; i < 4500; i++)
     {

         index_c1[i] = 0;
         index_c2[i] = 0;
         index_c3[i] = 0;
         index_c4[i] = 0;
         c1[i] = 0;
         c2[i] = 0;
         c3[i] = 0;
         c4[i] = 0;
         center_array[i] = 0;
     }*/
    /*cout << "centeroid 1 on random number " << r1 << " is  (" << c1_dist << ", " << c1_speed << ")  " << endl; ;
    cout << "centeroid 2 on random number " << r2 << " is  (" << c2_dist << ", " << c2_speed << ")  " << endl; ;
    cout << "centeroid 3 on random number " << r3 << " is  (" << c3_dist << ", " << c3_speed << ")  " << endl; ;
    cout << "centeroid 4 on random number " << r4 << " is  (" << c4_dist << ", " << c3_speed << ")  " << endl; ;
 */   sum1 = 0;
    sum2 = 0;
    dif = 0;
    x1 = 0; x2 = 0; x3 = 0; x4 = 0;
    for (int i = 0; i < count; i++)//this loop is for calculating different from every point
    {
        dif = sqrt(((array2[i][0] - c1_dist) * (array2[i][0] - c1_dist)) + ((array2[i][1] - c1_speed) * (array2[i][1] - c1_speed)));
        c1[i] = dif;
        dif = sqrt(((array2[i][0] - c2_dist) * (array2[i][0] - c2_dist)) + ((array2[i][1] - c2_speed) * (array2[i][1] - c2_speed)));
        c2[i] = dif;
        dif = sqrt(((array2[i][0] - c3_dist) * (array2[i][0] - c3_dist)) + ((array2[i][1] - c3_speed) * (array2[i][1] - c3_speed)));
        c3[i] = dif;
        dif = sqrt(((array2[i][0] - c4_dist) * (array2[i][0] - c4_dist)) + ((array2[i][1] - c4_speed) * (array2[i][1] - c4_speed)));
        c4[i] = dif;

    }









    //// dif = sqrt((array2[r1-2][0] - c1_dist) * (array2[r1-2][0] - c1_dist)) + ((array2[r1-2][1] - c1_speed) * (array2[r1-2][1] - c1_speed));
    //for (int i = 0; i < count; i++)
    //{
    //    // cout <<i<<"  :   " << c1[i] << "\t\t" << c2[i] << "\t\t" << c3[i] << "\t\t" << c4[i] << endl;
    //}

    for (int i = 0; i < count; i++)
    {
        if ((c1[i] < c2[i]) && (c1[i] < c3[i]) && (c1[i] < c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];

            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }

        else if (c1[i] == c2[i] && (c1[i] < c3[i]) && (c1[i] < c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            /// index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }
        else if (c1[i] < c2[i] && (c1[i] == c3[i]) && (c1[i] < c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }

        else if (c1[i] < c2[i] && (c1[i] < c3[i]) && (c1[i] == c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }

        else if (c1[i] == c2[i] && (c1[i] == c3[i]) && (c1[i] < c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }
        else if (c1[i] < c2[i] && (c1[i] == c3[i]) && (c1[i] == c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }

        else if (c1[i] == c2[i] && (c1[i] == c3[i]) && (c1[i] == c4[i]))
        {
            if (c4[i] == 0 || c3[i] == 0 || c2[i] == 0)
            {
                break;
            }
            else
            {

                k_1[x1][0] = array2[i][0];
                sum1 += k_1[x1][0];

                k_1[x1][1] = array2[i][1];

                sum2 += k_1[x1][1];
                center_array[i] = 1;
                x1++;
            }
        }
    }


    c_2_1_dist = sum1 / x1;
    c_2_1_speed = sum2 / x1;

    cout << "centeroid 1 number " << " is  (" << c_2_1_dist << ", " << c_2_1_speed << ")  " << endl; ;
    sum1 = 0;
    sum2 = 0;

    for (int i = 0; i < count; i++)
    {
        if ((c2[i] < c1[i]) && (c2[i] < c3[i]) && (c2[i] < c4[i]))
        {
            k_2[x2][0] = array2[i][0];
            sum1 += k_2[x2][0];
            k_2[x2][1] = array2[i][1];
            sum2 += k_2[x2][1];

            // index_c2[x2] = i;
            center_array[i] = 2;
            x2++;
        }
        else if ((c2[i] < c1[i]) && (c2[i] == c3[i]) && (c2[i] < c4[i]))
        {
            k_2[x2][0] = array2[i][0];
            sum1 += k_2[x2][0];
            k_2[x2][1] = array2[i][1];
            sum2 += k_2[x2][1];

            // index_c2[x2] = i;
            center_array[i] = 2;
            x2++;
        }

        else if ((c2[i] < c1[i]) && (c2[i] < c3[i]) && (c2[i] == c4[i]))
        {
            k_2[x2][0] = array2[i][0];
            sum1 += k_2[x2][0];
            k_2[x2][1] = array2[i][1];
            sum2 += k_2[x2][1];
            // index_c2[x2] = i;
            center_array[i] = 2;
            x2++;
        }
        else if ((c2[i] < c1[i]) && (c2[i] == c3[i]) && (c2[i] == c4[i]))
        {
            k_2[x2][0] = array2[i][0];
            sum1 += k_2[x2][0];
            k_2[x2][1] = array2[i][1];
            sum2 += k_2[x2][1];

            // index_c2[x2] = i;
            center_array[i] = 2;
            x2++;
        }
        /*

        else if ((c2[i] < c1[i]) && (c2[i] == c3[i]) && (c2[i] < c4[i]))
        {
            k_2[i] = c2[i];
            x2++;
        }
        else if ((c2[i] < c1[i]) && (c2[i] < c3[i]) && (c2[i] == c4[i]))
        {
            k_2[i] = c2[i];
            x2++;
        }*/

    }

    c_2_2_dist = sum1 / x2;
    c_2_2_speed = sum2 / x2;

    cout << "centeroid 1 number " << " is  (" << c_2_2_dist << ", " << c_2_2_speed << ")  " << endl;
    sum1 = 0;
    sum2 = 0;


    for (int i = 0; i < count; i++)
    {
        if ((c3[i] < c1[i]) && (c3[i] < c2[i]) && (c3[i] < c4[i]))
        {
            k_3[x3][0] = array2[i][0];
            sum1 += k_3[x3][0];
            k_3[x3][1] = array2[i][1];
            sum2 += k_3[x3][1];

            // index_c3[x3] = i;
            center_array[i] = 3;
            x3++;
        }
        else if ((c3[i] < c1[i]) && (c3[i] < c2[i]) && (c3[i] == c4[i]))
        {
            k_3[x3][0] = array2[i][0];
            sum1 += k_3[x3][0];
            k_3[x3][1] = array2[i][1];
            sum2 += k_3[x3][1];

            // index_c3[x3] = i;
            center_array[i] = 3;
            x3++;

        }

        /*else if ((c3[i] <  c1[i]) && (c3[i] == c2[i]) && (c3[i] < c4[i]))
        {
            k_3[i] = c3[i];
            x3++;
        }*/
        //else if ((c3[i] < c1[i]) && (c3[i] < c2[i]) && (c3[i] == c4[i]))
        //{
        //    k_3[i] = c3[i];
        //    x3++;
        //}
    }
    c_2_3_dist = sum1 / x3;
    c_2_3_speed = sum2 / x3;

    cout << "centeroid 2 number " << " is  (" << c_2_3_dist << ", " << c_2_3_speed << ")  " << endl;

    sum1 = 0;
    sum2 = 0;


    for (int i = 0; i < count; i++)
    {
        if ((c4[i] < c1[i]) && (c4[i] < c2[i]) && (c4[i] < c3[i]))
        {
            k_4[x4][0] = array2[i][0];
            sum1 += k_4[x4][0];
            k_4[x4][1] = array2[i][1];
            sum2 += k_4[x4][1];

            //  index_c4[x4] = i;
            center_array[i] = 4;
            x4++;
        }
        /* else if ((c4[i] == c1[i]) && (c4[i] < c2[i]) && (c4[i] < c3[i]))
         {
             k_4[i] = c4[i];
             x4++;
         }
         else if ((c4[i] < c1[i]) && (c4[i] == c2[i]) && (c4[i] < c3[i]))
         {
             k_4[i] = c4[i];
             x4++;
         }*/
         /*else if ((c4[i] < c1[i]) && (c4[i] < c2[i]) && (c4[i] == c3[i]))
         {
             k_4[i] = c4[i];
             x4++;
         }*/

    }

    c_2_4_dist = sum1 / x4;
    c_2_4_speed = sum2 / x4;

    cout << "centeroid 3 number " << " is  (" << c_2_4_dist << ", " << c_2_4_speed << ")  " << endl;
    sum1 = 0;
    sum2 = 0;
    int x = x1 + x2 + x3 + x4;
    cout << x1 << "\t\t" << x2 << "\t\t" << x3 << "\t\t" << x4 << endl;
    cout << x << endl;
    cout << "\n\n\n\n" << endl;
    cout << c_2_1_dist << "====" << c1_dist << "        " << c_2_2_dist << "====" << c2_dist << endl;
    cout << c_2_3_dist << "====" << c3_dist << "        " << c_2_4_dist << "====" << c4_dist << endl;
    cout << "\n\n\n\n" << endl;
    if ((c_2_1_dist == c1_dist) && (c_2_2_dist == c2_dist) && (c_2_3_dist == c3_dist) && (c_2_4_dist == c4_dist))

    {
        cout << "    So recent centeroid and privious centeroid become equal  " << endl;
        cout << endl;

    }
    else
    {
        //cout << " elsee condition  " << endl;
        c1_dist = c_2_1_dist;
        c2_dist = c_2_2_dist;
        c3_dist = c_2_3_dist;
        c4_dist = c_2_4_dist;
        c1_speed = c_2_1_speed;
        c2_speed = c_2_2_speed;
        c3_speed = c_2_3_speed;
        c4_speed = c_2_4_speed;


        c_2_1_dist = 0;
        c_2_2_dist = 0;
        c_2_3_dist = 0;
        c_2_4_dist = 0;
        c_2_1_speed = 0;
        c_2_2_speed = 0;
        c_2_3_speed = 0;
        c_2_4_speed = 0;


        goto kmean;
    }

    /*for (int i = 0; i < x1; i++)
    {
        cout << i + 1 << "  :  ";
        for (int j = 0; j < 2; j++)
        {

            cout << k_1[i][j] << " \t";
        }
        cout << endl;
    }*/

    /* for (int i = 0; i < count; i++)
     {
         cout << " this is index storing loop" << endl;
         if (index_c1[i] == i)
         {
             center_array[i] = 1;
         }
         else if (index_c2[i] == i)
         {
             center_array[i] = 2;
         }
         else if (index_c3[i] == i)
         {
             center_array[i] = 3;

         }
         else if (index_c4[i] == i)
         {
             center_array[i] = 4;
         }
     }*/
    /*for (int i = 0; i < count; i++)
    {
        cout<<i+1 <<"==";
        cout << center_array[i] << endl;
    }*/

    //string finalarray[4001][4];
   // string aa[4001];

    string** strings = new string * [40001];
    for (int i = 0; i < 4001; i++) {
        strings[i] = new string[4];
        for (int j = 0; j < 4; j++) {
            strings[i][j] = "";
        }
    }






   string* aa = new string[4001];
   for (int i = 0; i < 4001; i++) {
        aa[i] = "";
    }
    /*for (int i = 0; i < 4001; i++)
    {
        for (int j = 0; j < 4;j++)
        {
            strings[i][j] = " ";
        }
    }*/
    for (int i = 0; i < count; i++)
    {
        aa[i] = to_string(center_array[i]);

    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {

                strings[i][j] = aa[i];
            }
            // finalarray[i][j] = to_string(center_array[i]); 
            else
            {

                strings[i][j] = array[i][j];
            }
            //cout << array[i][j] << "\t\t";

       cout <<strings[i][j] << "\t\t";

        }
        cout << endl;

    }
    /*for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                array[i][j] = to_string(center_array[i]);
            }
        }
    }*/
    file.close();
    /*ofstream file;
    int j = 0,y2 = 0,y3=0;
    file.open("output.txt");
    for (int i = 0; i < count;i++)
    {
        j = 0;
        
          file << strings[i][j] << "," << strings[i][j + 1] << "," << strings[i][j + 2] << "," << strings[i][j + 3] << endl;
        
    }*/


    std::ofstream outfile;
    outfile.open("output.csv");
    string x12="ID", y="Distance", z= "Speed", w= "Cluster";
    outfile << x12 << "," << y << "," << z << "," << w << endl;
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 4; j++) {
            outfile << strings[i][j];
            if (j < 4 - 1) {
                outfile << ",";
            }
        }
        outfile << "\n";
    }

    outfile.close();

    for (int i = 0; i < count; i++) {
        delete[] strings[i];
    }
    delete[] strings;


    delete[] aa;

    return 0;


}