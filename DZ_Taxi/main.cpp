#include <iostream>
#include <random>

using namespace std;

class BusStop 
{
    double avgPassengerArrivalTime;
    double avgBusArrivalTime;
    bool isTerminalStop;
public:
    BusStop(double avgPassengerArrivalTime, double avgBusArrivalTime, bool isTerminalStop) :
        avgPassengerArrivalTime(avgPassengerArrivalTime), avgBusArrivalTime(avgBusArrivalTime), isTerminalStop(isTerminalStop) {}

    double getAveragePassengerArrivalTime() const 
    {
        return avgPassengerArrivalTime;
    }

    double getAverageBusArrivalTime() const 
    {
        return avgBusArrivalTime;
    }

    bool isTerminal() const 
    {
        return isTerminalStop;
    }
};

class Simulation 
{
    BusStop stop;
    int maxPeopleAtStop;
public:
    Simulation(const BusStop& stop, int maxPeopleAtStop) : stop(stop), maxPeopleAtStop(maxPeopleAtStop) {}

    double generateRandomWaitTime() 
    {
        return 1 + (rand() % 15);
    }

    double simulate()
    {
        double totalWaitTime = 0.0;
        int numPeople = 100; 

        for (int i = 0; i < numPeople; i++) {
            double waitTime = generateRandomWaitTime();
            totalWaitTime += waitTime;
        }
        return totalWaitTime / numPeople;
    }
};

int main() 
{
    BusStop stop(10.0, 30.0, false); 
    Simulation simulation(stop, 20); 
    double avgTime = simulation.simulate();

    cout << "Average time spent at the bus stop: " << avgTime << " minutes" << std::endl;

    return 0;
}