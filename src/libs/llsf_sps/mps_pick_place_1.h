/*!
* \file mps_pick_place_1.h
* \brief Definition of communication between Refbox and Pick&Place 1
* \author David Masternak
* \version 1.0
*/

#ifndef MPSPICKPLACE1_H
#define MPSPICKPLACE1_H

#include <mps_refbox_interface.h>
#include <modbus/modbus.h>
#include <mps.h>

/*!
* \class MPSPickPlace1
* \brief This class handels the communication to a Pick&Place 1
*/
class MPSPickPlace1 : public MPS{
 public:
  /*!
   * \fn MPSPickPlace1(MPSRefboxInterface* cli, int addr)
   * \brief Initialize communication
   * \param cli reference to refbox client
   * \param addr address of destination MPS
   */
  MPSPickPlace1(MPSRefboxInterface* cli, int addr);
  
  /*!
   * \fn produceEnd()
   * \brief send command to produce workpiece
   */
  void produceEnd();

  /*!
   * \fn isEmpty()
   * \brief receive isEmpty command
   * \param empty received isEmpty command
   * \return true, if lane is empty or false, if lane is not empty
   */
  bool isEmpty(bool empty);

  /*!
   * \fn isReady()
   * \brief receive isReady command
   * \param received isEmpty command
   * \return true, if workpiece is ready or false, if workpiece is not ready
   */
  bool isReady(bool ready);

  /*!
   * \fn receiveData()
   * \brief receive data from MPS and capsulate this data into the MPSMessage datastruct.
   */
  void receiveData();

  /*!
   * \fn sendData()
   * \brief write data from MPS and encapsulate this data into the modbus protocol datastruct.
   */
  void sendData();

 private:
  modbus_t* ctx; // connection to server
  int addr; // address of destination MPS
};

#endif // MPSPICKPLACE1_H
