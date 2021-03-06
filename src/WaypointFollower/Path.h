#pragma once

#include "PathSegment.h"
#include "CORELogging/CORELog.h"
#include <vector>
#include <algorithm>
#include "json.hpp"

using namespace CORE;
using namespace nlohmann;
using namespace std;

struct Waypoint {
	Translation2d position;
	double speed;
	std::string event;
	Waypoint(Translation2d pos = Translation2d(0,0), double spd = 0.0, std::string completeEvent = "");
};

class Path {
protected:
	vector<Waypoint> m_waypoints;
	vector<PathSegment> m_segments;
	vector<string> m_events;
public:
	Path();
	Path(vector<Waypoint> waypoints, bool flipY = false, bool flipX = false);
	static Path fromFile(string fileName, bool flip);
	static Path fromText(string text, bool flip);
	Waypoint getFirstWaypoint();
	double update(Translation2d pos);
	bool eventPassed(string event);
	double getRemainingLength();
	PathSegment::Sample getLookaheadPoint(Translation2d pos, double lookahead);
	pair<bool, Translation2d> getFirstCircleSegmentIntersection(PathSegment segment, Translation2d center,
																	 double radius);
	// Position2d getClosestPoint(Translation2d pos);
};
