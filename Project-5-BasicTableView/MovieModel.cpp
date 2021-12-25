#include "MovieModel.h"

#include <QFile>

MovieModel::MovieModel(QObject *parent) : QAbstractListModel(parent)
{
    populateData();
}

QHash<int, QByteArray> MovieModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FilmRole] = "film";
    roles[GenreRole] = "genre";
    roles[LeadStudioRole] = "lead";
    roles[AudienceScoreRole] = "audienceScore";
    roles[ProfitabilityRole] = "profitability";
    roles[RottenTomatoesRole] = "rottenTomatoes";
    roles[WorldwideGrossRole] = "worldwideGross";
    roles[YearRole] = "year";
    return roles;
}

int MovieModel::rowCount(const QModelIndex &) const
{
    return m_movies.size();
}

QVariant MovieModel::data(const QModelIndex &index, int role) const
{
    if (!hasIndex(index.row(), index.column(), index.parent()))
    {
        return {};
    }

    switch(static_cast<AnimalRoles>(role))
    {
    case AnimalRoles::FilmRole: return m_movies.at(index.row()).film();
    case AnimalRoles::GenreRole: return m_movies.at(index.row()).genre();
    case AnimalRoles::LeadStudioRole: return m_movies.at(index.row()).leadStudio();
    case AnimalRoles::AudienceScoreRole: return m_movies.at(index.row()).audienceScore();
    case AnimalRoles::ProfitabilityRole: return m_movies.at(index.row()).profitability();
    case AnimalRoles::RottenTomatoesRole: return m_movies.at(index.row()).rottenTomatoes();
    case AnimalRoles::WorldwideGrossRole: return m_movies.at(index.row()).worldwideGross();
    case AnimalRoles::YearRole: return m_movies.at(index.row()).year();
    }

    return {};
}

void MovieModel::populateData()
{
    QFile file(":/movies.csv");
    file.open(QIODevice::ReadOnly);
    for (auto const &line: file.readAll().split('\n'))
    {
        if (line.isEmpty())
        {
            continue;
        }
        QList<QString> fields = QString(line).split(',');
        Movie m(fields.at(0), fields.at(1), fields.at(2), fields.at(3).toInt(),
                fields.at(4).toDouble(), fields.at(5).toInt(),
                fields.at(6), fields.at(7).toInt());
        m_movies.append(m);
    }
}
