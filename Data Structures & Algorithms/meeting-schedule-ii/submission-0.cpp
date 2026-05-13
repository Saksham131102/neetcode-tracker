/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for(auto &interval : intervals) {
            int s = interval.start;
            int e = interval.end;
            mp[s]++;
            mp[e]--;
        }
        int maxRooms = 0;
        int rooms = 0;
        for(auto it : mp) {
            rooms += it.second;
            maxRooms = max(maxRooms, rooms);
        }

        return maxRooms;
    }
};
