#include <iostream>
#include <string>
#include <curl/curl.h>

// Callback function to handle the response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    // Initialize the CURL library
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Initialize a CURL handle
    curl = curl_easy_init();
    if (curl) {
        // Set the URL for the GET request
        auto res = curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com");
        if (res != CURLE_OK) {
			std::cerr << "cURL failed to set URL: " << curl_easy_strerror(res) << std::endl;
			return 1;
		}

        // Set the write function to capture the response data
        auto res2 = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        if (res2 != CURLE_OK) {
            std::cerr << "cURL failed to set URL: " << curl_easy_strerror(res2) << std::endl;
            return 1;
        }

        auto res3  = curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        if (res3 != CURLE_OK) {
            std::cerr << "cURL failed to set URL: " << curl_easy_strerror(res3) << std::endl;
            return 1;
        }
       auto cert =  curl_easy_setopt(curl, CURLOPT_CAINFO, "C:\\Users\\z004f3rj\\Documents\\Laptop Data\\Learning_Material\\curl_example\\CURL_DEMO\\cacert-2024-09-24.pem");
       if (cert != CURLE_OK) {
			std::cerr << "cURL failed to set URL: " << curl_easy_strerror(cert) << std::endl;
			return 1;
		}
        // Perform the request
        auto res4 = curl_easy_perform(curl);

        // Check for errors
        if (res4 != CURLE_OK) {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res4) << std::endl;
        }
        else {
            // Print the response
            std::cout << "Response data: " << readBuffer << std::endl;
        }

        // Clean up the CURL handle
        curl_easy_cleanup(curl);
    }

    // Clean up global cURL environment
    curl_global_cleanup();

    return 0;
}
