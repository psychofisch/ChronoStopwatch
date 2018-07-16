#pragma once

#include <chrono>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class ChronoStopwatch
{
public:
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

	// statics
	// returns the given time (in seconds) in the format HH:MM:SS.mmmm
	static std::string getFormatString(double nmbr);

private:
	typedef std::chrono::high_resolution_clock::time_point timepoint;
	typedef std::pair<timepoint, size_t> timepointIndex;
	
	std::vector<timepoint> mStart;
	std::vector<timepointIndex> mStop;
};

