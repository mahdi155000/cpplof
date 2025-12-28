#include "Movie.hpp"

Movie::Movie(const std::string& title, Type type)
    : title_(title), type_(type), season_(1), episode_(1), watched_(false){}

// Getters
const std::string& Movie::getTitle() const { return  title_; }
Movie::Type Movie::getType() const { return type_; }
int Movie::getSeason() const { return season_;}
int Movie::getEpisode() const { return episode_; }
bool Movie::isWatched() const { return watched_; }


// Progress Control
void Movie::markWatched() { watched_ = true; }
void Movie::markUnwatched() { watched_ = false; }

void Movie::nextEpisode()
{
    if (type_ == Type::Series)
        ++episode_;
}
void Movie::previousEpisode()
{
    if (type_ == Type::Series)
        --episode_;
}

void Movie::resetProgress()
{
    season_ = 1;
    episode_ = 1;
    watched_ = false;
}
