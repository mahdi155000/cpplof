#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>

class Movie
{
public:
    enum class Type
    {
        Movie,
        Series,
    };

    // ---- Constructor ----
    Movie(const std::string& title, Type type);

    // ---- Getters ----
    const std::string& getTitle() const;
    Type getType() const;
    int getSeason() const;
    int getEpisode() const;
    bool isWatched() const;

    // ---- Progress control ----
    void markWatched();
    void markUnwatched();
    void nextEpisode();
    void previousEpisode();
    void resetProgress();

private:
    std::string title_;
    Type type_;
    int season_;
    int episode_;
    bool watched_;
};

#endif // MOVIE_HPP
