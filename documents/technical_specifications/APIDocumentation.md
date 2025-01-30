# API Documentation

<details>
    <summary>Table of contents</summary>

- [API Documentation](#api-documentation)
  - [Overview](#overview)
  - [Endpoints](#endpoints)
    - [1. Get Quickest Path](#1-get-quickest-path)
  - [Contact](#contact)

</details>

## Overview

This document provides details about the API endpoints, request formats, and responses.

## Endpoints

### 1. Get Quickest Path

**Endpoint:** `GET /quickest-path?source={SourceID}&destination{DestinationID}`

> [!IMPORTANT]
> Accepted formats:
>
> | Format             | description                                                     |
> | ------------------ | --------------------------------------------------------------- |
> | `application/json` | The API will return a response in JSON                          |
> | `application/xml`  | The API will return a response in XML                           |
> | `*/*`              | **(default)** The API will return a response in JSON by default |

**Request Example:**

```bash
curl -X GET "http://localhost/quickest-path?source=7&destination=12" \
     -H "Accept: application/json, application/xml"
```

> [!NOTE]
>
> - Replace `http://localhost` with the actual API URL *(if not in localhost anymore)*.

**Response Example:**

```json
{
  "total_distance": 123,
  "steps": [
    {
      "source": "7",
      "destination": "23",
      "distance": 10
    },
    {
      "source": "23",
      "destination": "12",
      "distance": 20
    }
  ]
}
```

## Contact

For support, open an issue on our github repository on the link [HERE](https://github.com/algosup/2024-2025-project-3-quickest-path-team-5/issues).
