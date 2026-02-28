# basic web application architecture
- client: web browser formats and renders HTML
- java code runs on the server hardware. webserver + application code
- data is stored in files or a database
- referred to as a three-tier or three-layer architecture

# model-view controller (MVC)
- a design pattern used to structure a GUI or web application
- model - the data and code using the data
    - does not depend on how data might be input or displayed
- controller - act on input, use model to do processing & update/get data, tell view to update/get data, tell view to update the display & pass data
    - coordinates and delegates

# development environment
- work on your local machine
- use a web server written in Java
- follow the basic Jakarta EE standards

# tomcat web server
- an open-source implementation of the core Java web services
    - one of a number of available servers: e.g. Jetty, WebLogic, WebSphere, Geronimo, GlassFish
    - Tomcat is more used for dev than for deployment
- written in Java

# web servers
- a web server receives http requests, processes each request, and returns an http response
    - the default port is 80, but typically 8080 for development
- each request is mapped to a service handler, using a mapping from the URL Path to a file or a servlet
- the server is multi-threaded, so requests can be handled concurrently, or in parallel on a multi-core machine

# what is a servlet?
- a servlet is a Java class that plugs into the Jakarta EE framework for web apps
    - rather than writing out an entire application, the framework provides the overall structure and behaviour
    - write classes and code to specialise the framework to be our application
- a URL can be mpped to a servlet, so that the servlet is run to generate the response

# servlet life cycle
- at runtime one servlet object is created for each Servlet class
- a `servlet` extends `HttpServlet`, which defines the following core methods:
    - `init` - called once when the servlet object is created. Can override to do any extra initialisation
    - `service` - called in a new thread for each request. It calls `doGet`, `doPost` depending on the HTTP request type. Should not be overridden
    - `doGet`, `doPost` handle requests. Override these to implement the behaviour your app needs
    - `destroy` - called when the servlet object is taken out of use (e.g. server shutting down). Override to clean upb but may never be called if server crashes

# servlets and threads
- the server starts a new thread for each request
    - it does not create a new Servlet object
- the same servlet object must handle multiple threads (thread safety)
- for this module threading issues will be ignored'

# `WebServlet`
- `@WebServlet("/helloworld.html")`
    - the URL path relative to the document root directory on the server
    - this means `localhost:8080/helloworld.html` if files are in the `webapp` directory
    - or `localhost:8080/myApp/helloworld.html` if the app is in the webapp directory
    - and all other URLs used in your app that refer to the app must include the correct directories in the path
    - a server may be running several applications, with the files kept in different directories

# Request and Response Object
- `HttpServletRequest` request
    - Contains information about the request made to invoke servlet.
    - headers, cookies, parameters, and lots more
    - numerous utility methods
- `HttpServletResponse` response
    - has methods to provide information for building the HTTP response
    - collects the output, e.g., html, via a `PrintWriter`
    - numerous utility methods

# war files
- war == Web Archive
  - actually a `.zip` format file
- a web app is packaged into a war file for deployment
- war file is loaded into the application directory of the web server
- the web server unpacks the file
  - files/dirs put into place
- initialises the application
- then ready to go

# Java server pages
- we do not want servlets generating html directly
- instead, the servlet should delegate to another class to create the web page
  - a version of the MVC design pattern
  - model == java classes, view == JSP, controller == servlet
- a Java Server Page looks like an html file with Java code embedded within
  - can also use JSP tags or libraries like Thymeleaf to avoid Java code
  - tags are implemented in Java so there is still Java code, just not visible
- JSPs are actually servlets, with the Java code generated from the JSP source by the JSP compiler
- they use standard HTML for most of the webpage content
- special tags, not part of HTML, markup embedded Java code
- there are tag libraries of JSP tags that are implemented in Java

# scripting elements
- expressions: <%=expression=>
- scriplets:<%code%>
  - Java code that is inserted into the generated serlet's `_jspService` method as is, and compiled.
  - must be valid Java code with semicolons etc.
- declarations: <%!code%>
  - Java code that is inserted into the servlet body outside of any methods (e.g. instance variable)

# variables accessible in a JSP
- `request` - the`HttpServletRequest`
- `response` - the `HttpServletResponse`
- `out` - a `JspWriter`, wrapper for a `PrintStream` with methods like `print`, `println`, which all throw `IOExceptions` if an error occurs
- `session` - the `HttpSession` object accessible to servlets
- `application` - the `ServletContext`, which can be used for sharing data

# Java import statements in JSP
- as the JSP is converted to a Java servlet, there must be import statements for `List` and other libraries
- this is done by adding directives at the top of the JSP before the `<html>` tag
  - `<%@ page import="java.util.List"%>`
- add of these for each class/interface needed in a JSP page

# headers, footers, and shared content
- you typically want your web pages to have a common layout:
  - header section, with title, logo, navigation bar, etc.
  - footer, with info about the site, contact info, copyright, etc.
  - shared CSS files
- avoid duplication and copy and paste content
