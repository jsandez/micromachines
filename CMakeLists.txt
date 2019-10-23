cmake_minimum_required(VERSION 3.10.2)
project(micromachines)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

message("[INFO] Agregando '${CMAKE_SOURCE_DIR}/3rd-party' como directorio de includes")
include_directories(${CMAKE_SOURCE_DIR}/3rd-party)

message("[INFO] Agregando Box2D como libreria")
file(GLOB_RECURSE BOX2D_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "3rd-party/Box2D/*.cpp" "3rd-party/Box2D/*.h")
add_library(Box2D STATIC ${BOX2D_SOURCES})

#FILE(GLOB 3RD_PARTY 3rd-party/Box2D/*.cpp)
FILE(GLOB CLIENT_SRCFILES RELATIVE ${CMAKE_SOURCE_DIR} src/Client/*.cpp src/Client/*.h)

ADD_EXECUTABLE(client ${CLIENT_SRCFILES} ${LIBS_SOURCES} src/Client/Dot.cpp src/Client/Dot.h src/Client/Pista.cpp src/Client/Pista.h)
target_link_libraries(client SDL2 SDL2_image)

install(FILES assets/Finish.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/Road_01/Road_01_Tile_01/Road_01_Tile_01.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/Road_01/Road_01_Tile_02/Road_01_Tile_02.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/Road_01/Road_01_Tile_03/Road_01_Tile_03.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/Road_01/Road_01_Tile_04/Road_01_Tile_04.png DESTINATION ${CMAKE_BINARY_DIR})

#[[include_directories(3rd-party/Box2D)
include_directories(3rd-party/Box2D/Collision)
include_directories(3rd-party/Box2D/Collision/Shapes)
include_directories(3rd-party/Box2D/Common)
include_directories(3rd-party/Box2D/Dynamics)
include_directories(3rd-party/Box2D/Dynamics/Contacts)
include_directories(3rd-party/Box2D/Dynamics/Joints)
include_directories(3rd-party/Box2D/Rope)
include_directories(3rd-party/Box2D/src)
include_directories(3rd-party/Box2D/src/Collision)
include_directories(3rd-party/Box2D/src/Collision/Shapes)
include_directories(3rd-party/Box2D/src/Common)
include_directories(3rd-party/Box2D/src/Dynamics)
include_directories(3rd-party/Box2D/src/Dynamics/Contacts)
include_directories(3rd-party/Box2D/src/Dynamics/Joints)
include_directories(3rd-party/Box2D/src/Rope)

add_executable(micromachines
        3rd-party/Box2D/Collision/Shapes/b2ChainShape.cpp
        3rd-party/Box2D/Collision/Shapes/b2ChainShape.h
        3rd-party/Box2D/Collision/Shapes/b2CircleShape.cpp
        3rd-party/Box2D/Collision/Shapes/b2CircleShape.h
        3rd-party/Box2D/Collision/Shapes/b2EdgeShape.cpp
        3rd-party/Box2D/Collision/Shapes/b2EdgeShape.h
        3rd-party/Box2D/Collision/Shapes/b2PolygonShape.cpp
        3rd-party/Box2D/Collision/Shapes/b2PolygonShape.h
        3rd-party/Box2D/Collision/Shapes/b2Shape.h
        3rd-party/Box2D/Collision/b2BroadPhase.cpp
        3rd-party/Box2D/Collision/b2BroadPhase.h
        3rd-party/Box2D/Collision/b2CollideCircle.cpp
        3rd-party/Box2D/Collision/b2CollideEdge.cpp
        3rd-party/Box2D/Collision/b2CollidePolygon.cpp
        3rd-party/Box2D/Collision/b2Collision.cpp
        3rd-party/Box2D/Collision/b2Collision.h
        3rd-party/Box2D/Collision/b2Distance.cpp
        3rd-party/Box2D/Collision/b2Distance.h
        3rd-party/Box2D/Collision/b2DynamicTree.cpp
        3rd-party/Box2D/Collision/b2DynamicTree.h
        3rd-party/Box2D/Collision/b2TimeOfImpact.cpp
        3rd-party/Box2D/Collision/b2TimeOfImpact.h
        3rd-party/Box2D/Common/b2BlockAllocator.cpp
        3rd-party/Box2D/Common/b2BlockAllocator.h
        3rd-party/Box2D/Common/b2Draw.cpp
        3rd-party/Box2D/Common/b2Draw.h
        3rd-party/Box2D/Common/b2GrowableStack.h
        3rd-party/Box2D/Common/b2Math.cpp
        3rd-party/Box2D/Common/b2Math.h
        3rd-party/Box2D/Common/b2Settings.cpp
        3rd-party/Box2D/Common/b2Settings.h
        3rd-party/Box2D/Common/b2StackAllocator.cpp
        3rd-party/Box2D/Common/b2StackAllocator.h
        3rd-party/Box2D/Common/b2Timer.cpp
        3rd-party/Box2D/Common/b2Timer.h
        3rd-party/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h
        3rd-party/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h
        3rd-party/Box2D/Dynamics/Contacts/b2CircleContact.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2CircleContact.h
        3rd-party/Box2D/Dynamics/Contacts/b2Contact.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2Contact.h
        3rd-party/Box2D/Dynamics/Contacts/b2ContactSolver.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2ContactSolver.h
        3rd-party/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h
        3rd-party/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h
        3rd-party/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h
        3rd-party/Box2D/Dynamics/Contacts/b2PolygonContact.cpp
        3rd-party/Box2D/Dynamics/Contacts/b2PolygonContact.h
        3rd-party/Box2D/Dynamics/Joints/b2DistanceJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2DistanceJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2FrictionJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2FrictionJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2GearJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2GearJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2Joint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2Joint.h
        3rd-party/Box2D/Dynamics/Joints/b2MotorJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2MotorJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2MouseJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2MouseJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2PrismaticJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2PulleyJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2PulleyJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2RevoluteJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2RopeJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2RopeJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2WeldJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2WeldJoint.h
        3rd-party/Box2D/Dynamics/Joints/b2WheelJoint.cpp
        3rd-party/Box2D/Dynamics/Joints/b2WheelJoint.h
        3rd-party/Box2D/Dynamics/b2Body.cpp
        3rd-party/Box2D/Dynamics/b2Body.h
        3rd-party/Box2D/Dynamics/b2ContactManager.cpp
        3rd-party/Box2D/Dynamics/b2ContactManager.h
        3rd-party/Box2D/Dynamics/b2Fixture.cpp
        3rd-party/Box2D/Dynamics/b2Fixture.h
        3rd-party/Box2D/Dynamics/b2Island.cpp
        3rd-party/Box2D/Dynamics/b2Island.h
        3rd-party/Box2D/Dynamics/b2TimeStep.h
        3rd-party/Box2D/Dynamics/b2World.cpp
        3rd-party/Box2D/Dynamics/b2World.h
        3rd-party/Box2D/Dynamics/b2WorldCallbacks.cpp
        3rd-party/Box2D/Dynamics/b2WorldCallbacks.h
        3rd-party/Box2D/Rope/b2Rope.cpp
        3rd-party/Box2D/Rope/b2Rope.h
        3rd-party/Box2D/src/Collision/Shapes/b2ChainShape.cpp
        3rd-party/Box2D/src/Collision/Shapes/b2ChainShape.h
        3rd-party/Box2D/src/Collision/Shapes/b2CircleShape.cpp
        3rd-party/Box2D/src/Collision/Shapes/b2CircleShape.h
        3rd-party/Box2D/src/Collision/Shapes/b2EdgeShape.cpp
        3rd-party/Box2D/src/Collision/Shapes/b2EdgeShape.h
        3rd-party/Box2D/src/Collision/Shapes/b2PolygonShape.cpp
        3rd-party/Box2D/src/Collision/Shapes/b2PolygonShape.h
        3rd-party/Box2D/src/Collision/Shapes/b2Shape.h
        3rd-party/Box2D/src/Collision/b2BroadPhase.cpp
        3rd-party/Box2D/src/Collision/b2BroadPhase.h
        3rd-party/Box2D/src/Collision/b2CollideCircle.cpp
        3rd-party/Box2D/src/Collision/b2CollideEdge.cpp
        3rd-party/Box2D/src/Collision/b2CollidePolygon.cpp
        3rd-party/Box2D/src/Collision/b2Collision.cpp
        3rd-party/Box2D/src/Collision/b2Collision.h
        3rd-party/Box2D/src/Collision/b2Distance.cpp
        3rd-party/Box2D/src/Collision/b2Distance.h
        3rd-party/Box2D/src/Collision/b2DynamicTree.cpp
        3rd-party/Box2D/src/Collision/b2DynamicTree.h
        3rd-party/Box2D/src/Collision/b2TimeOfImpact.cpp
        3rd-party/Box2D/src/Collision/b2TimeOfImpact.h
        3rd-party/Box2D/src/Common/b2BlockAllocator.cpp
        3rd-party/Box2D/src/Common/b2BlockAllocator.h
        3rd-party/Box2D/src/Common/b2Draw.cpp
        3rd-party/Box2D/src/Common/b2Draw.h
        3rd-party/Box2D/src/Common/b2GrowableStack.h
        3rd-party/Box2D/src/Common/b2Math.cpp
        3rd-party/Box2D/src/Common/b2Math.h
        3rd-party/Box2D/src/Common/b2Settings.cpp
        3rd-party/Box2D/src/Common/b2Settings.h
        3rd-party/Box2D/src/Common/b2StackAllocator.cpp
        3rd-party/Box2D/src/Common/b2StackAllocator.h
        3rd-party/Box2D/src/Common/b2Timer.cpp
        3rd-party/Box2D/src/Common/b2Timer.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2ChainAndCircleContact.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2ChainAndCircleContact.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2ChainAndPolygonContact.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2ChainAndPolygonContact.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2CircleContact.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2CircleContact.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2Contact.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2Contact.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2ContactSolver.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2ContactSolver.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2EdgeAndCircleContact.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2EdgeAndCircleContact.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2EdgeAndPolygonContact.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2PolygonAndCircleContact.h
        3rd-party/Box2D/src/Dynamics/Contacts/b2PolygonContact.cpp
        3rd-party/Box2D/src/Dynamics/Contacts/b2PolygonContact.h
        3rd-party/Box2D/src/Dynamics/Joints/b2DistanceJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2DistanceJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2FrictionJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2FrictionJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2GearJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2GearJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2Joint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2Joint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2MotorJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2MotorJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2MouseJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2MouseJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2PrismaticJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2PrismaticJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2PulleyJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2PulleyJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2RevoluteJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2RevoluteJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2RopeJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2RopeJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2WeldJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2WeldJoint.h
        3rd-party/Box2D/src/Dynamics/Joints/b2WheelJoint.cpp
        3rd-party/Box2D/src/Dynamics/Joints/b2WheelJoint.h
        3rd-party/Box2D/src/Dynamics/b2Body.cpp
        3rd-party/Box2D/src/Dynamics/b2Body.h
        3rd-party/Box2D/src/Dynamics/b2ContactManager.cpp
        3rd-party/Box2D/src/Dynamics/b2ContactManager.h
        3rd-party/Box2D/src/Dynamics/b2Fixture.cpp
        3rd-party/Box2D/src/Dynamics/b2Fixture.h
        3rd-party/Box2D/src/Dynamics/b2Island.cpp
        3rd-party/Box2D/src/Dynamics/b2Island.h
        3rd-party/Box2D/src/Dynamics/b2TimeStep.h
        3rd-party/Box2D/src/Dynamics/b2World.cpp
        3rd-party/Box2D/src/Dynamics/b2World.h
        3rd-party/Box2D/src/Dynamics/b2WorldCallbacks.cpp
        3rd-party/Box2D/src/Dynamics/b2WorldCallbacks.h
        3rd-party/Box2D/src/Rope/b2Rope.cpp
        3rd-party/Box2D/src/Rope/b2Rope.h
        3rd-party/Box2D/src/Box2D.h
        3rd-party/Box2D/Box2D.h src/mainMicromachines.cpp src/Area.cpp src/Area.h)]]
