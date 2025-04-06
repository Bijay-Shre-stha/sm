#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i, run = 10;
    int r1[] = {6, 3, 8, 2, 8, 5, 7, 1, 4, 5}; // inter-arrival time
    int r2[] = {3, 5, 2, 6, 3, 2, 3, 4, 2, 4}; // service time
    float st, awt, pcu, wt = 0, iat = 0, it, sb, se = 0, cit = 0, cat = 0, cwt = 0, tci = 0, tqs = 0, tis = 0, ti = 0;
    int total_inter_arrival = 0, total_service_time = 0, total_waiting_time = 0, total_time_in_system = 0, total_idle_time = 0;
    cout << "Bijay Shrestha" << endl;
    cout << setw(5) << "Customer" << setw(5) << "IAT" << setw(10) << "Arrival" << setw(10) << "Service"
         << setw(10) << "Start" << setw(10) << "Wait" << setw(10) << "Ends" << setw(10) << "Spends" << setw(10) << "Idle" << endl;
    for (i = 0; i < run; ++i)
    {
        iat = r1[i];
        cat = cat + iat;
        total_inter_arrival += iat;
        if (cat >= se)
        {
            sb = cat;
            it = sb - se;
            cit = cit + it;
            wt = 0;
        }
        else
        {
            sb = se;
            wt = se - cat;
            cwt = cwt + wt;
            it = 0;
        }
        st = r2[i];
        se = sb + st;
        tqs = se - cat;
        tis = se - cat;
        ti = it;
        total_service_time += r2[i];
        total_waiting_time += wt;
        total_time_in_system += tqs;
        total_idle_time += it;
        cout << setw(5) << i + 1 << setw(5) << r1[i] << setw(10) << fixed << setprecision(0) << cat
             << setw(10) << r2[i] << setw(10) << sb << setw(10) << wt << setw(10) << se << setw(10) << tqs
             << setw(10) << it << endl;
    }
    awt = static_cast<float>(total_waiting_time) / run;
    pcu = static_cast<float>(se - cit) * 100 / se;
    cout << setw(5) << "Total" << setw(5) << total_inter_arrival << setw(10) << "" << setw(10)
         << total_service_time << setw(10) << "" << setw(10) << total_waiting_time << setw(10) << ""
         << setw(10) << total_time_in_system << setw(10) << total_idle_time << endl;
    cout << "\nAverage waiting time: " << fixed << setprecision(4) << awt;
    cout << "\nPercentage capacity utilization: " << fixed << setprecision(2) << pcu << "%\n";
    return 0;
}
