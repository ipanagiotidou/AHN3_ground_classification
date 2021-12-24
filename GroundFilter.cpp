/*
  GEO1015.2021
  hw03 
  --
  [YOUR NAME] 
  [YOUR STUDENT NUMBER] 
  [YOUR NAME] 
  [YOUR STUDENT NUMBER] 
*/

#include "GroundFilter.h"

// -- LAS reading and writing
#include <lasreader.hpp>
#include <laswriter.hpp>

// -- CGAL delaunay triangulation
#include <CGAL/Projection_traits_xy_3.h>
#include <CGAL/Delaunay_triangulation_2.h>

// -- CGAL kd-tree
#include <CGAL/Orthogonal_k_neighbor_search.h>
#include <CGAL/Search_traits_3.h>

double findMax(std::set<double> my_set)
{
    // Get the maximum element
    double max_element;
    if (!my_set.empty())
        max_element = *(my_set.rbegin());

    // return the maximum element
    return max_element;
}

double findMin(std::set<double> my_set)
{
    // Get the minimum element
    double min_element;
    if (!my_set.empty())
        min_element = *my_set.begin();

    // return the minimum element
    return min_element;
}

void groundfilter_tin(const std::vector<Point>& pointcloud, const json& jparams) {
  /*
    !!! TO BE COMPLETED !!!
      
    Function that performs ground filtering using TIN refinement and writes the result to a new LAS file.

    !!! You are free to subdivide the functionality of this function into several functions !!!
      
    Inputs:
      pointcloud: input point cloud (an Nx3 numpy array),
      jparams: a dictionary jparams with all the parameters that are to be used in this function:
        - resolution:    resolution (cellsize) for the initial grid that is computed as part of the ground filtering algorithm,
        - distance:      distance threshold used in the ground filtering algorithm,
        - angle:         angle threshold used in the ground filtering algorithm in degrees,
        - output_las:    path to output .las file that contains your ground classification,
  */
  typedef CGAL::Projection_traits_xy_3<Kernel>  Gt;
  typedef CGAL::Delaunay_triangulation_2<Gt> DT;

  //print the first 5 values
    for(int i = 0; i < 5; i++){
        std::cout << pointcloud[i][0] << std::endl;
    }

    // Find the bounding box
    std::set<double> my_set_x;
    std::set<double> my_set_y;
    for(const auto & i : pointcloud){
        my_set_x.insert(i[0]);
        my_set_y.insert(i[1]);
    }
    // Get the minimum element X
    std::cout << "Minimum element X: " << findMin(my_set_x) << std::endl;
    // Get the maximum element X
    std::cout << "Maximum element X: " << findMax(my_set_x) << std::endl;
    // Get the minimum element Y
    std::cout << "Minimum element Y: " << findMin(my_set_y) << std::endl;
    // Get the maximum element Y
    std::cout << "Maximum element Y: " << findMax(my_set_y) << std::endl;


  // double resolution = jparams["resolution"];
  // double distance = jparams["distance"];
  // double angle = jparams["angle"];
  // std::string output_las = jparams["output_las"];


  //-- TIP CGAL triangulation -> https://doc.cgal.org/latest/Triangulation_2/index.html
  //-- Insert points in a triangulation: [https://doc.cgal.org/latest/Triangulation_2/classCGAL_1_1Triangulation__2.html#a1025cd7e7226ccb44d82f0fb1d63ad4e]
  // DT dt;
  // dt.insert(Point(0,0,0));
  // dt.insert(Point(10,0,0));
  // dt.insert(Point(0,10,0));
  //-- Find triangle that intersects a given point: [https://doc.cgal.org/latest/Triangulation_2/classCGAL_1_1Triangulation__2.html#a940567120751e7864c7b345eaf756642]
  // DT::Face_handle triangle = dt.locate(Point(3,3,0));
  //-- get the 3 vertices of the triangle: 
  // DT::Vertex_handle v0 = triangle->vertex(0);
  // DT::Vertex_handle v1 = triangle->vertex(1);
  // DT::Vertex_handle v2 = triangle->vertex(2);
  // get the coordinates of the three vertices:
  // std::cout << "v0 has the coordinates ( " << v0->point().x() << "  " << v0->point().y() << " " << v0->point().z() << " )" << std::endl;
  // std::cout << "v1 has the coordinates ( " << v1->point().x() << "  " << v1->point().y() << " " << v1->point().z() << " )" << std::endl;
  // std::cout << "v2 has the coordinates ( " << v2->point().x() << "  " << v2->point().y() << " " << v2->point().z() << " )" << std::endl;

  //-- TIP CGAL compute squared distance between two points: [https://doc.cgal.org/latest/Kernel_23/group__squared__distance__grp.html#ga1ff73525660a052564d33fbdd61a4f71]
  // std::cout << "the squared distance between v0 and v1 is: " << CGAL::squared_distance(v0->point(), v1->point()) << std::endl;
  
  //-- TIP
  //-- write the results to a new LAS file
  // std::vector<int> class_labels;
  // write_lasfile(jparams["output_las"], pointcloud, class_labels);
}



void groundfilter_csf(const std::vector<Point>& pointcloud, const json& jparams) {
  /*
  !!! TO BE COMPLETED !!!
    
  Function that performs ground filtering using CSF and writes the result to a new LAS file.

  !!! You are free to subdivide the functionality of this function into several functions !!!
    
  Inputs:
    pointcloud: input point cloud (an Nx3 numpy array),
    jparams: a dictionary with all the parameters that are to be used in this function:
      - resolution:     resolution of the cloth grid,
      - epsilon_zmax:   tolerance to stop the iterations,
      - epsilon_ground: threshold used to classify ground points,
      - output_las:     path to output .las file that contains your ground classification
  */
  typedef CGAL::Search_traits_3<Kernel> TreeTraits;
  typedef CGAL::Orthogonal_k_neighbor_search<TreeTraits> Neighbor_search;
  typedef Neighbor_search::Tree Tree;

  // double resolution = jparams["resolution"];
  // double epsilon_zmax = jparams["epsilon_zmax"];
  // double epsilon_ground = jparams["epsilon_ground"];
  // std::string output_las = jparams["output_las"];

  // //-- print the first 5 points in the pointcloud, which are CGAL Point_3
  // //-- https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Point__3.html
  // int i = 0;
  // for (auto p : pointcloud) {
  //   std::cout << "(" << p.x() << ", " << p.y() << ", " << p.z()  << ")" << std::endl;
  //   i++;
  //   if (i == 5)
  //     break;
  // }

  //-- TIP
  //-- construct and query kd-tree:
  // https://doc.cgal.org/latest/Spatial_searching/index.html#title5
  //
  // Tree tree(pointcloud.begin(), pointcloud.end());
  // const unsigned int N = 1;
  // Point query_point = Point(0,0,0);
  // Neighbor_search search_result(tree, query_point, N);
  //
  // for(auto res : search_result) {
  //   Point neighbour_point = res.first;
  //   double distance = res.second;
  // }

  //-- TIP
  //-- write the results to a new LAS file
  // std::vector<int> class_labels;
  // write_lasfile(jparams["output_las"], pointcloud, class_labels);
}



std::vector<Point> read_lasfile(const json& jparams) {
  /*
  Function to read points from a LAS file

  Inputs:
    jparams["filename"]:   the filename to read the LAS file to

  Returns:
    a std::vector<Point> with the points from the LAS file
  */
  std::string filename = jparams["filename"];
	LASreadOpener lasreadopener;
	lasreadopener.set_file_name(filename.c_str());
	LASreader* lasreader = lasreadopener.open();
	
	if (!lasreader){
		std::cerr << "cannot read las file: " << filename << "\n";
		exit(1);
	}

  //-- store each point in a CGAL Point_3 object
  //-- https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Point__3.html
	std::vector<Point> points;
	while (lasreader->read_point()) {
		points.push_back( 
			Point(
				lasreader->point.get_x(),
				lasreader->point.get_y(),
				lasreader->point.get_z()
			)
		);
	}
	lasreader->close();
	delete lasreader;

	return points;
}



void write_lasfile(const std::string filename, const std::vector<Point>& pointcloud, const std::vector<int>& class_labels) {
  /*
  Function to write a new LAS file with point labels (for the LAS classification field)

  Inputs:
    filename:   the filename to write the LAS file to
    pointcloud: input point cloud (a vector of Points),
    Labels:     Contains point labels. Should be a vector of ints of the same size as pointcloud (ie. one label for each point in the same order as pointcloud). Uses LAS classification codes, ie 2 = ground. 1 = unclassified.
  */
  LASwriteOpener laswriteopener;
  laswriteopener.set_file_name(filename.c_str());

  LASheader lasheader;
  lasheader.x_scale_factor = 0.01;
  lasheader.y_scale_factor = 0.01;
  lasheader.z_scale_factor = 0.01;
  lasheader.x_offset = 0.0;
  lasheader.y_offset = 0.0;
  lasheader.z_offset = 0.0;
  lasheader.point_data_format = 0;
  lasheader.point_data_record_length = 20;

  LASpoint laspoint;
  laspoint.init(&lasheader, lasheader.point_data_format, lasheader.point_data_record_length, 0);

  LASwriter* laswriter = laswriteopener.open(&lasheader);
  if (laswriter == 0)
  {
    std::cerr << "ERROR: could not open laswriter\n";
    exit(1);
  }

	if (pointcloud.size()!=class_labels.size()) {
		std::cerr << "ERROR: points has a different size than class_labels\n";
		exit(1);
	}

  for (size_t i=0; i<pointcloud.size(); ++i) {
		const Point& p = pointcloud[i];
		const int& label = class_labels[i];

    laspoint.set_x(p[0]);
    laspoint.set_y(p[1]);
    laspoint.set_z(p[2]);
		laspoint.set_classification(label);

    laswriter->write_point(&laspoint);
    laswriter->update_inventory(&laspoint);    
  } 

  laswriter->update_header(&lasheader, TRUE);
  laswriter->close();
  delete laswriter;
}