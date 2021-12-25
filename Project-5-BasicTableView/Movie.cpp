#include "Movie.h"

Movie::Movie(const QString &film, const QString &genre, const QString &leadStudio,
             uint16_t audienceScore, double profitability, uint16_t rottenTomatoes,
             const QString &m_worldwideGross, uint16_t year):
    m_film(film),
    m_genre(genre),
    m_leadStudio(leadStudio),
    m_audienceScore(audienceScore),
    m_profitability(profitability),
    m_rottenTomatoes(rottenTomatoes),
    m_worldwideGross(m_worldwideGross),
    m_year(year)
{
}

const QString &Movie::film() const
{
    return m_film;
}

void Movie::setFilm(const QString &newFilm)
{
    m_film = newFilm;
}

const QString &Movie::genre() const
{
    return m_genre;
}

void Movie::setGenre(const QString &newGenre)
{
    m_genre = newGenre;
}

const QString &Movie::leadStudio() const
{
    return m_leadStudio;
}

void Movie::setLeadStudio(const QString &newLeadStudio)
{
    m_leadStudio = newLeadStudio;
}

uint16_t Movie::audienceScore() const
{
    return m_audienceScore;
}

void Movie::setAudienceScore(uint16_t newAudienceScore)
{
    m_audienceScore = newAudienceScore;
}

double Movie::profitability() const
{
    return m_profitability;
}

void Movie::setProfitability(double newProfitability)
{
    m_profitability = newProfitability;
}

uint16_t Movie::rottenTomatoes() const
{
    return m_rottenTomatoes;
}

void Movie::setRottenTomatoes(uint16_t newRottenTomatoes)
{
    m_rottenTomatoes = newRottenTomatoes;
}

const QString &Movie::worldwideGross() const
{
    return m_worldwideGross;
}

void Movie::setWorldwideGross(const QString &newWorldwideGross)
{
    m_worldwideGross = newWorldwideGross;
}

uint16_t Movie::year() const
{
    return m_year;
}

void Movie::setYear(uint16_t newYear)
{
    m_year = newYear;
}
