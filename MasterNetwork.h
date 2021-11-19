#ifndef MASTERNETWORK_H
#define MASTERNETWORK_H

#include "network.h"
/**
 * @class MasterNetwork
 * @brief Class to hold global network of satellites
 */
class MasterNetwork {

  public:
      /**
        * @brief Gets singleton or instantiates it if non exists
        * @return The Master Network
      */
	  static MasterNetwork* instance();
        /**
          * @return The network list of the MasterNetwork
        */
    Network* network();
        /**
          * @param[out] deletes network and then instantiates a new one
        */
    void clearNetwork();
    
  protected:
      /**
        * @brief creates a new instance of Netwwork
      */
      MasterNetwork();
      MasterNetwork(const MasterNetwork&);
      MasterNetwork& operator=(const MasterNetwork&);
      /**
        * @brief destructor deletes network list
      */
      ~MasterNetwork();

  private:
      /**
        * @brief the network list
      */
    Network* nw; 

      /**
        * @brief pointer to master netwrok
      */
	  static MasterNetwork* singleton;
	
};


#endif