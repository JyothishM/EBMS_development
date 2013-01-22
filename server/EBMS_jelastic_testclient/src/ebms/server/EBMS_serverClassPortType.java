/**
 * EBMS_serverClassPortType.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package ebms.server;

public interface EBMS_serverClassPortType extends java.rmi.Remote {
    public java.lang.String doOperation(java.lang.String user, java.lang.String password, java.lang.String level, java.lang.String oper) throws java.rmi.RemoteException;
    public java.lang.Boolean login(java.lang.String user, java.lang.String password) throws java.rmi.RemoteException;
    public java.lang.Boolean hasPrivilege(java.lang.String user, java.lang.String password, java.lang.String level, java.lang.String oper) throws java.rmi.RemoteException;
}
