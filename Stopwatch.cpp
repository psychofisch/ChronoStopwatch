#include "Stopwatch.h"

ChronoStopwatch::ChronoStopwatch()
{
	
}


ChronoStopwatch::~ChronoStopwatch()
{
}

size_t ChronoStopwatch::start()
{
	mStart.push_back(std::chrono::high_resolution_clock::now());
	return mStart.size() - 1;
}

double ChronoStopwatch::stop(size_t i)
{
	mStop.push_back(timepointIndex(std::chrono::high_resolution_clock::now(), i));
	auto diff = std::chrono::duration_cast<std::chrono::duration<double>>(mStop[i] - mStart);
	return m_count - 1;
}

double ChronoStopwatch::getDuration(size_t count) const
{
	if (count >= mStop.size() || count >= mStart.size())
	{
		return -1.0;
	}
	std::chrono::duration<double> d = std::chrono::duration_cast<std::chrono::duration<double>>(mStop[count] - mStart[count]);
	return d.count();
}

std::string ChronoStopwatch::getDurationString(int count)
{
	double d = getDuration(count);
	return getFormatted(d);
}

std::string ChronoStopwatch::getFormatted(double nmbr)
{
	std::stringstream test;	
	std::chrono::duration<double> diff(nmbr);

	auto hours = std::chrono::duration_cast<std::chrono::hours>(diff);
	diff -= hours;

	auto mins = std::chrono::duration_cast<std::chrono::minutes>(diff);
	diff -= mins;

	auto secs = std::chrono::duration_cast<std::chrono::seconds>(diff);
	diff -= secs;

	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(diff);

	test << std::setfill('0');
	test << std::setw(2) << hours.count() << ':'
		<< std::setw(2) << mins.count() << ':'
		<< std::setw(2) << secs.count() << '.'
		<< std::setw(3) << millis.count();

	return test.str();
}
