#pragma once

#include <chrono>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class ChronoStopwatch
{
public:
	typedef std::chrono::high_resolution_clock::time_point timepoint;
	enum Action { START, STOP };

	ChronoStopwatch();
	~ChronoStopwatch();
	
	// starts a new timer
	size_t start();
	// stops the last timer and returns its duration
	double stop();
	// stops the given timer and returns its duration
	double stop(size_t i);
	// returns the duration of a specific timer
	double getDuration(size_t i) const;
	std::string getDurationString(int count);
	std::string getFormatted(double nmbr);

private:
	typedef std::pair<timepoint, size_t> timepointIndex;
	
	std::vector<timepoint> mStart;
	std::vector<timepointIndex> mStop;
};

