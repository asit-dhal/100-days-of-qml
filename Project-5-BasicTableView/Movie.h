#pragma once

#include <QString>

class Movie
{
public:
    Movie(const QString &film, const QString &genre, const QString &leadStudio,
          uint16_t audienceScore, double profitability, uint16_t rottenTomatoes,
          const QString &m_worldwideGross, uint16_t year);

    const QString &film() const;
    void setFilm(const QString &newFilm);

    const QString &genre() const;
    void setGenre(const QString &newGenre);

    const QString &leadStudio() const;
    void setLeadStudio(const QString &newLeadStudio);

    uint16_t audienceScore() const;
    void setAudienceScore(uint16_t newAudienceScore);

    double profitability() const;
    void setProfitability(double newProfitability);

    uint16_t rottenTomatoes() const;
    void setRottenTomatoes(uint16_t newRottenTomatoes);

    const QString &worldwideGross() const;
    void setWorldwideGross(const QString &newWorldwideGross);

    uint16_t year() const;
    void setYear(uint16_t newYear);

private:
     QString m_film;
     QString m_genre;
     QString m_leadStudio;
     uint16_t m_audienceScore;
     double m_profitability;
     uint16_t m_rottenTomatoes;
     QString m_worldwideGross;
     uint16_t m_year;
};

