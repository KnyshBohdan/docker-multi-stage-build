# Combination of Python and C++ via multi-stage build

This project demonstrates how to generate a CSV file using Python and process it using a C++ program that calculates the mean of each column using the Eigen library.
The project is containerized using Docker with a multi-stage build for efficient image creation.

### Building and Running the Project

To build and run the project using Docker, follow these steps:

1. Clone the repository:

```shell
git clone https://github.com/yourusername/csv-data-processing.git
cd csv-data-processing
```

2. Build the Docker image:

```shell
docker build -t csv-mean .
```

3. Run the Docker container:

```shell
docker run --rm csv-mea
```
