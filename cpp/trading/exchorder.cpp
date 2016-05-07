#include "exchorder.h"

namespace kg {
namespace trading {

std::ostream& operator<<(std::ostream& os, const ExchOrder& o) {
    os << "ExchOrder"
        << "\nid ...... " << o.getId()
        << "\naction .. " << o.getAction()
        << "\nprice ... " << o.getPrice()
        << "\nside .... " << o.getSide()
        << "\nsymbol .. " << o.getSymbol();
    return os;
}

std::ostream& operator<<(std::ostream& os, const ExchOrderUpdate& u) {
    os << "ExchOrderUpdate"
        << "\nid ...... " << u.getId()
        << "\nupdatetype .. " << u.getUpdateType()
        << "\nquantity .... " << u.getQuantity()
        << "\nprice ....... " << u.getPrice()
        << "\nreason ...... " << u.getReason();
    return os;
}


} // close namespace trading
} // close namespace kg
