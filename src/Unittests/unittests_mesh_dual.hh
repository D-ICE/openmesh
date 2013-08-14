#ifndef INCLUDE_UNITTESTS_MESHDUAL_HH
#define INCLUDE_UNITTESTS_MESHDUAL_HH

#include <gtest/gtest.h>
#include <Unittests/unittests_common.hh>
#include <OpenMesh/Tools/Dualizer/meshDualT.hh>

class OpenMeshMeshDual : public OpenMeshBasePoly {

    protected:

        // This function is called before each test is run
        virtual void SetUp() {
            
            // Do some initial stuff with the member data here...
        }

        // This function is called after all tests are through
        virtual void TearDown() {

            // Do some final stuff with the member data here...
        }

    // Member already defined in OpenMeshBase
    //Mesh mesh_;  
};

/*
 * ====================================================================
 * Define tests below
 * ====================================================================
 */

/*
 */
TEST_F(OpenMeshMeshDual, Dualize) {

  bool ok = OpenMesh::IO::read_mesh(mesh_, "cube1.off");
    
  ASSERT_TRUE(ok);

  PolyMesh* dualMesh;

  dualMesh = OpenMesh::Util::MeshDual(mesh_);


  std::cerr << "Original has " << mesh_.n_vertices() << " , " << mesh_.n_edges() << " , "  << mesh_.n_faces() << std::endl;

  EXPECT_EQ(15048u, dualMesh->n_vertices()) << "The number of vertices after decimation is not correct!";
  EXPECT_EQ(22572u, dualMesh->n_edges()) << "The number of edges after decimation is not correct!";
  EXPECT_EQ(7526u, dualMesh->n_faces()) << "The number of faces after decimation is not correct!";

  delete(dualMesh);
}

#endif // INCLUDE GUARD