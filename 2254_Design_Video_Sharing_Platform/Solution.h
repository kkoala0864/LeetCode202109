#include <data_type.h>

class VideoSharingPlatform {
	public:
		VideoSharingPlatform() {}

		int upload(string video) {
			int vid = -1;
			if (deleteId.empty()) {
				vid = videoContent.size();
				videoContent.emplace_back(video);
				metadata.push_back({0,0,0});
			} else {
				vid = *(deleteId.begin());
				deleteId.erase(vid);
				videoContent[vid] = video;
			}
			return vid;
		}

		void remove(int videoId) {
			if (deleteId.count(videoId) || videoId >= videoContent.size()) return;
			if (videoId >= videoContent.size()) return;
			videoContent[videoId] = "";
			for (int i = 0 ; i < 3 ; ++i) metadata[videoId][i] = 0;
			deleteId.emplace(videoId);
		}

		string watch(int videoId, int startMinute, int endMinute) {
			if (deleteId.count(videoId) || videoId >= videoContent.size()) return "-1";

			++metadata[videoId][2];
			int tail = min((int)videoContent[videoId].size() - 1, endMinute);
			return videoContent[videoId].substr(startMinute, tail - startMinute + 1);
		}

		void like(int videoId) {
			if (deleteId.count(videoId) || videoId >= videoContent.size()) return;
			++metadata[videoId][0];
		}

		void dislike(int videoId) {
			if (deleteId.count(videoId) || videoId >= videoContent.size()) return;
			++metadata[videoId][1];
		}

		vector<int> getLikesAndDislikes(int videoId) {
			if (deleteId.count(videoId) || videoId >= videoContent.size()) return {-1};
			return vector<int>({metadata[videoId][0], metadata[videoId][1]});
		}

		int getViews(int videoId) {
			if (deleteId.count(videoId) || videoId >= videoContent.size()) return -1;
			return metadata[videoId][2];
		}
private:
	vector<string> videoContent;
	vector<vector<int>> metadata; //[like, dislike, view]
	set<int> deleteId;
	virtual ~VideoSharingPlatform() {
	}
	VideoSharingPlatform &operator=(const VideoSharingPlatform &source);
	VideoSharingPlatform(const VideoSharingPlatform &);
};
