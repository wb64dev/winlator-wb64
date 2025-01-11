
```
#import <Foundation/Foundation.h>

int main(int argc, char *argv[]) {
    @autoreleasepool {
        // Create server
        NSURL *baseURL = [NSURL URLWithString:@"http://localhost:8080"];
        HTTPServer *server = [[HTTPServer alloc] init];
        [server setPort:8080];
        [server setDocumentRoot:[[NSBundle mainBundle] resourcePath]];

        // Handle requests
        [server setConnectionClass:[MyConnection class]];

        // Start server
        NSError *error;
        if ([server start:&error]) {
            NSLog(@"Server started on %@", baseURL);
            [[NSRunLoop mainRunLoop] run];
        } else {
            NSLog(@"Error starting server: %@", error);
        }
    }
    return 0;
}

// MyConnection class handles incoming requests
@interface MyConnection : HTTPConnection
@end

@implementation MyConnection

- (void)handleRequest:(HTTPRequest *)request {
    NSString *method = [request method];
    NSString *path = [request path];

    NSLog(@"Received %@ request to %@", method, path);

    // Send response
    HTTPResponse *response = [[HTTPResponse alloc] initWithStatusCode:200];
    [response setHeader:@"Content-Type" value:@"text/html"];
    NSString *html = @"<html><body>Hello World!</body></html>";
    [response setBodyWithString:html];
    [self sendResponse:response];
}

@end
```
