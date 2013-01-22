
/**
 * EBMS_serverClassCallbackHandler.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis2 version: 1.6.2  Built on : Apr 17, 2012 (05:33:49 IST)
 */

    package ebms.server;

    /**
     *  EBMS_serverClassCallbackHandler Callback class, Users can extend this class and implement
     *  their own receiveResult and receiveError methods.
     */
    public abstract class EBMS_serverClassCallbackHandler{



    protected Object clientData;

    /**
    * User can pass in any object that needs to be accessed once the NonBlocking
    * Web service call is finished and appropriate method of this CallBack is called.
    * @param clientData Object mechanism by which the user can pass in user data
    * that will be avilable at the time this callback is called.
    */
    public EBMS_serverClassCallbackHandler(Object clientData){
        this.clientData = clientData;
    }

    /**
    * Please use this constructor if you don't want to set any clientData
    */
    public EBMS_serverClassCallbackHandler(){
        this.clientData = null;
    }

    /**
     * Get the client data
     */

     public Object getClientData() {
        return clientData;
     }

        
           /**
            * auto generated Axis2 call back method for doOperation method
            * override this method for handling normal response from doOperation operation
            */
           public void receiveResultdoOperation(
                    ebms.server.EBMS_serverClassStub.DoOperationResponse result
                        ) {
           }

          /**
           * auto generated Axis2 Error handler
           * override this method for handling error response from doOperation operation
           */
            public void receiveErrordoOperation(java.lang.Exception e) {
            }
                
           /**
            * auto generated Axis2 call back method for hasPrivilege method
            * override this method for handling normal response from hasPrivilege operation
            */
           public void receiveResulthasPrivilege(
                    ebms.server.EBMS_serverClassStub.HasPrivilegeResponse result
                        ) {
           }

          /**
           * auto generated Axis2 Error handler
           * override this method for handling error response from hasPrivilege operation
           */
            public void receiveErrorhasPrivilege(java.lang.Exception e) {
            }
                
           /**
            * auto generated Axis2 call back method for login method
            * override this method for handling normal response from login operation
            */
           public void receiveResultlogin(
                    ebms.server.EBMS_serverClassStub.LoginResponse result
                        ) {
           }

          /**
           * auto generated Axis2 Error handler
           * override this method for handling error response from login operation
           */
            public void receiveErrorlogin(java.lang.Exception e) {
            }
                


    }
    