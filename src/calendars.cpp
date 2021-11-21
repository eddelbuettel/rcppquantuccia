
#include <RcppQuantuccia_types.h>

void RcppQuantuccia::CalendarContainer::setCalendar(const std::string txt = "TARGET")  {
    if (txt != m_id) {
        m_id = txt;
        if (txt == "TARGET") {
            p_cal.reset(new ql::TARGET);

        } else if (txt == "UnitedStates" ||
                   txt == "UnitedStates/Settlement" ||
                   txt == "UnitedStates::Settlement") {
            p_cal.reset(new ql::UnitedStates(ql::UnitedStates::Settlement));
        } else if (txt == "UnitedStates/LiborImpact" ||
                   txt == "UnitedStates::LiborImpact") {
            p_cal.reset(new ql::UnitedStates(QuantLib::UnitedStates::LiborImpact));
        } else if (txt == "UnitedStates/NYSE" ||
                   txt == "UnitedStates::NYSE") {
            p_cal.reset(new ql::UnitedStates(QuantLib::UnitedStates::NYSE));
        } else if (txt == "UnitedStates/GovernmentBond" ||
                   txt == "UnitedStates::GovernmentBond") {
            p_cal.reset(new ql::UnitedStates(ql::UnitedStates::GovernmentBond));
        } else if (txt == "UnitedStates/NERC" ||
                   txt == "UnitedStates::NERC") {
            p_cal.reset(new ql::UnitedStates(ql::UnitedStates::NERC));
        } else if (txt == "UnitedStates/FederalReserve" ||
                   txt == "UnitedStates::FederalReserve") {
            p_cal.reset(new ql::UnitedStates(ql::UnitedStates::FederalReserve));

        } else if (txt == "Argentina") {
            p_cal.reset(new ql::Argentina());

        } else if (txt == "Australia") {
            p_cal.reset(new ql::Australia());

        } else if (txt == "Austria" ||
                   txt == "Austria/Settlement" ||
                   txt == "Austria::Settlement") {
            p_cal.reset(new ql::Austria(ql::Austria::Settlement));
        } else if (txt == "Austria/Exchange" ||
                   txt == "Austria::Exchange") {
            p_cal.reset(new ql::Austria(ql::Austria::Exchange));

        } else if (txt == "Bespoke") {
            p_cal.reset(new ql::BespokeCalendar());

        } else if (txt == "Botswana") {
            p_cal.reset(new ql::Botswana());

        } else if (txt == "Brazil" ||
                   txt == "Brazil/Settlement" ||
                   txt == "Brazil::Settlement") {
            p_cal.reset(new ql::Brazil(ql::Brazil::Settlement));
        } else if (txt == "Brazil/Exchange" ||
                   txt == "Brazil::Exchange") {
            p_cal.reset(new ql::Brazil(ql::Brazil::Exchange));

        } else if (txt == "Canada" ||
                   txt == "Canada/Settlement" ||
                   txt == "Canada::Settlement") {
            p_cal.reset(new ql::Canada(ql::Canada::Settlement));
        } else if (txt == "Canada/TSX" ||
                   txt == "Canada::TSX") {
            p_cal.reset(new ql::Canada(ql::Canada::TSX));

        } else if (txt == "Chile") {
            p_cal.reset(new ql::Chile());

        } else if (txt == "China" ||
                   txt == "China/SSE" ||
                   txt == "China::SSE") {
            p_cal.reset(new ql::China(ql::China::SSE));
        } else if (txt == "China/IB" ||
                   txt == "China::IB") {
            p_cal.reset(new ql::China(ql::China::IB));

        } else if (txt == "CzechRepublic") {
            p_cal.reset(new ql::CzechRepublic());

        } else if (txt == "Denmark") {
            p_cal.reset(new ql::Denmark());

        } else if (txt == "Finland") {
            p_cal.reset(new ql::Finland());

        } else if (txt == "France" ||
                   txt == "France/Settlement" ||
                   txt == "France::Settlement") {
            p_cal.reset(new ql::France(ql::France::Settlement));
        } else if (txt == "France/Exchange" ||
                   txt == "France::Exchange") {
            p_cal.reset(new ql::France(ql::France::Exchange));

        } else if (txt == "Germany" ||
                   txt == "Germany/Settlement" ||
                   txt == "Germany::Settlement") {
            p_cal.reset(new ql::Germany(ql::Germany::Settlement));
        } else if (txt == "Germany/FrankfurtStockExchange" ||
                   txt == "Germany::FrankfurtStockExchange") {
            p_cal.reset(new ql::Germany(ql::Germany::FrankfurtStockExchange));
        } else if (txt == "Germany/Xetra" ||
                   txt == "Germany::Xetra") {
            p_cal.reset(new ql::Germany(ql::Germany::Xetra));
        } else if (txt == "Germany/Eurex" ||
                   txt == "Germany::Eurex") {
            p_cal.reset(new ql::Germany(ql::Germany::Eurex));
        } else if (txt == "Germany/Euwax" ||
                   txt == "Germany::Euwax") {
            p_cal.reset(new ql::Germany(ql::Germany::Euwax));

        } else if (txt == "HongKong") {
            p_cal.reset(new ql::HongKong());

        } else if (txt == "Hungary") {
            p_cal.reset(new ql::Hungary());

        } else if (txt == "Iceland") {
            p_cal.reset(new ql::Iceland());

        } else if (txt == "India") {
            p_cal.reset(new ql::India());

        } else if (txt == "Indonesia") {
            p_cal.reset(new ql::Indonesia());

        } else if (txt == "Israel") {
            p_cal.reset(new ql::Israel());

        } else if (txt == "Italy" ||
                   txt == "Italy/Settlement" ||
                   txt == "Italy::Settlement") {
            p_cal.reset(new ql::Italy(ql::Italy::Settlement));
        } else if (txt == "Italy/Exchange" ||
                   txt == "Italy::Exchange") {
            p_cal.reset(new ql::Italy(ql::Italy::Exchange));

        } else if (txt == "Japan") {
            p_cal.reset(new ql::Japan());

        } else if (txt == "Mexico") {
            p_cal.reset(new ql::Mexico());

        } else if (txt == "NewZealand") {
            p_cal.reset(new ql::NewZealand());

        } else if (txt == "Norway") {
            p_cal.reset(new ql::Norway());

        } else if (txt == "Null" ||
                   txt == "null" ||
                   txt == "NULL") {
            p_cal.reset(new ql::NullCalendar());

        } else if (txt == "Poland") {
            p_cal.reset(new ql::Poland());

        } else if (txt == "Romania") {
            p_cal.reset(new ql::Romania());

        } else if (txt == "Russia") {
            p_cal.reset(new ql::Russia());

        } else if (txt == "SaudiArabia") {
            p_cal.reset(new ql::SaudiArabia());

        } else if (txt == "Singapore") {
            p_cal.reset(new ql::Singapore());

        } else if (txt == "Slovakia") {
            p_cal.reset(new ql::Slovakia());

        } else if (txt == "SouthAfrica") {
            p_cal.reset(new ql::SouthAfrica());

        } else if (txt == "SouthKorea" ||
                   txt == "SouthKorea/Settlement" ||
                   txt == "SouthKorea::Settlement") {
            p_cal.reset(new ql::SouthKorea(ql::SouthKorea::Settlement));
        } else if (txt == "SouthKorea/KRX" ||
                   txt == "SouthKorea::KRX") {
            p_cal.reset(new ql::SouthKorea(ql::SouthKorea::KRX));

        } else if (txt == "Sweden") {
            p_cal.reset(new ql::Sweden());

        } else if (txt == "Switzerland") {
            p_cal.reset(new ql::Switzerland());

        } else if (txt == "Taiwan") {
            p_cal.reset(new ql::Taiwan());

        } else if (txt == "Thailand") {
            p_cal.reset(new ql::Thailand());

        } else if (txt == "Turkey") {
            p_cal.reset(new ql::Turkey());

        } else if (txt == "Ukraine") {
            p_cal.reset(new ql::Ukraine());

        } else if (txt == "UnitedKingdom" ||
                   txt == "UnitedKingdom/Settlement" ||
                   txt == "UnitedKingdom::Settlement") {
            p_cal.reset(new ql::UnitedKingdom(ql::UnitedKingdom::Settlement));
        } else if (txt == "UnitedKingdom/Exchange" ||
                   txt == "UnitedKingdom::Exchange") {
            p_cal.reset(new ql::UnitedKingdom(ql::UnitedKingdom::Exchange));
        } else if (txt == "UnitedKingdom/Metals" ||
                   txt == "UnitedKingdom::Metals") {
            p_cal.reset(new ql::UnitedKingdom(ql::UnitedKingdom::Metals));

        } else if (txt == "WeekendsOnly") {
            p_cal.reset(new ql::WeekendsOnly());

        } else {        // fallback
            Rcpp::warning("Unrecognised calendar '%s' using fallback 'TARGET'", txt);
            p_cal.reset(new ql::TARGET);
        }
    }
}
