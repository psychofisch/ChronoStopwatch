#include "ChronoStopwatch.h"

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

double ChronoStopwatch::stop()
{
	size_t index = mStart.size() - 1;

	for (size_t x = mStop.size() - 1; mStop.size() > 0 && x >= 0; x--)
	{
		if (mStop[x].second == index)
		{
			if (index > 0)
			{
				index--;
				x = mStop.size();
			}
			else
				return -1.0;
		}

		if (x == 0)
			break;
	}

	return this->stop(index);
}

double ChronoStopwatch::stop(size_t i)
{
	mStop.push_back(timepointIndex(std::chrono::high_resolution_clock::now(), i));
	return this->getDuration(i);
}

double ChronoStopwatch::getDuration(size_t i) const
{
	timepointIndex endTime;
	bool found = false;

	for (size_t x = 0; x < mStop.size(); x++)
	{
		if (mStop[x].second == i)
		{
			endTime = mStop[x];
			found = true;
			break;
		}
	}

	if (found)
	{
		auto d = std::chrono::duration_cast<std::chrono::duration<double>>(endTime.first - mStart[i]);
		return d.count();
	}
	else
		return -1.0;
}

std::string ChronoStopwatch::getFormatString(double nmbr)
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
