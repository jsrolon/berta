berta
=====

Berta is a basic, extensible ray tracing application. For now berta only runs on OSX.

This project takes code, both directly and with modifications, from [pbrt-v2][1] and Sverre Kvaale's implementations of Kevin Suffern's ray tracer, available [here][2].

Design
------
The project is structured in a way that hopefully makes conceptual sense. Components used around the whole application, such as the geometry and transformations, are stored in the **utils** folder.

### Geometry
The geometry classes, both conceptually and in implementation, are taken from [pbrt][1]. They were chosen because they support a wide range of operations using operator overloading. The `Assert` checks were removed from all methods.

[1]: https://github.com/mmp/pbrt-v2
[2]: http://www.raytracegroundup.com/downloads.html
