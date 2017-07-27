#pragma once

#include <string>
#include <unordered_map>

#include "envoy/server/http_route_manager.h"

#include "common/router/rds_impl.h"

namespace Envoy {
namespace Server {

class HttpRouteManagerImpl : public HttpRouteManager {
public:
  HttpRouteManagerImpl() {}
  ~HttpRouteManagerImpl() {}

  // Server::HttpRouteManager
  std::vector<Router::RouteConfigProviderSharedPtr> routeConfigProviders() override;
  void
  addRouteConfigProvider(const std::string& name,
                         std::weak_ptr<Router::RouteConfigProvider> routeConfigProvider) override;
  Router::RouteConfigProviderSharedPtr getRouteConfigProvider(const std::string& name) override;
  void removeRouteConfigProvider(const std::string& name) override;

private:
  std::unordered_map<std::string, std::weak_ptr<Router::RouteConfigProvider>>
      route_config_providers_;
};
} // namespace Server
} // namespace Envoy