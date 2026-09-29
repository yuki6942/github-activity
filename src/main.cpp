#include <iostream>
#include <curl/curl.h>
#include <string>

int main() 
{

    CURL *curl;
    CURLcode result;

    curl = curl_easy_init();
    if (curl == NULL) 
    {
        fprintf(stderr, "HTTP request failed");
        return -1;
    }

    std::string username = "";
    std::cout << "Enter a username: ";
    std::cin >> username;

    if (username.empty()) 
    {
        fprintf(stderr, "Username needed\n");
        return -1;
    }

    std::string url = "https://api.github.com/users/" + username + "/events";

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "github-activity");
    result = curl_easy_perform(curl);

    if (result != CURLE_OK)
    {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
        return -1;
    }

    curl_easy_cleanup(curl);
    return 0;
}