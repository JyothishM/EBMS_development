package ebms.server;

public class EBMS_serverClassPortTypeProxy implements ebms.server.EBMS_serverClassPortType {
  private String _endpoint = null;
  private ebms.server.EBMS_serverClassPortType eBMS_serverClassPortType = null;
  
  public EBMS_serverClassPortTypeProxy() {
    _initEBMS_serverClassPortTypeProxy();
  }
  
  public EBMS_serverClassPortTypeProxy(String endpoint) {
    _endpoint = endpoint;
    _initEBMS_serverClassPortTypeProxy();
  }
  
  private void _initEBMS_serverClassPortTypeProxy() {
    try {
      eBMS_serverClassPortType = (new ebms.server.EBMS_serverClassLocator()).getEBMS_serverClassHttpSoap11Endpoint();
      if (eBMS_serverClassPortType != null) {
        if (_endpoint != null)
          ((javax.xml.rpc.Stub)eBMS_serverClassPortType)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
        else
          _endpoint = (String)((javax.xml.rpc.Stub)eBMS_serverClassPortType)._getProperty("javax.xml.rpc.service.endpoint.address");
      }
      
    }
    catch (javax.xml.rpc.ServiceException serviceException) {}
  }
  
  public String getEndpoint() {
    return _endpoint;
  }
  
  public void setEndpoint(String endpoint) {
    _endpoint = endpoint;
    if (eBMS_serverClassPortType != null)
      ((javax.xml.rpc.Stub)eBMS_serverClassPortType)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
    
  }
  
  public ebms.server.EBMS_serverClassPortType getEBMS_serverClassPortType() {
    if (eBMS_serverClassPortType == null)
      _initEBMS_serverClassPortTypeProxy();
    return eBMS_serverClassPortType;
  }
  
  public java.lang.String doOperation(java.lang.String user, java.lang.String password, java.lang.String level, java.lang.String oper) throws java.rmi.RemoteException{
    if (eBMS_serverClassPortType == null)
      _initEBMS_serverClassPortTypeProxy();
    return eBMS_serverClassPortType.doOperation(user, password, level, oper);
  }
  
  public java.lang.Boolean login(java.lang.String user, java.lang.String password) throws java.rmi.RemoteException{
    if (eBMS_serverClassPortType == null)
      _initEBMS_serverClassPortTypeProxy();
    return eBMS_serverClassPortType.login(user, password);
  }
  
  public java.lang.Boolean hasPrivilege(java.lang.String user, java.lang.String password, java.lang.String level, java.lang.String oper) throws java.rmi.RemoteException{
    if (eBMS_serverClassPortType == null)
      _initEBMS_serverClassPortTypeProxy();
    return eBMS_serverClassPortType.hasPrivilege(user, password, level, oper);
  }
  
  
}