import http, { createServer } from 'http'

const server = createServer((req, res) => {
    if (req.url === "/hello") {
        res.writeHead(200, {"content-Type": "text/plain"})
        res.end("Hello World!")
    }
    else {
        res.writeHead(200, {"content-Type": "text/plain"})
        res.end("Bye")
    }
})

server.listen(3001)