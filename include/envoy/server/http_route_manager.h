#pragma once

#include "envoy/router/rds.h"

namespace Envoy {
namespace Server {

class HttpRouteManager {
public:
  virtual ~HttpRouteManager() {}

  /**
   * @return std::vector<Router::RouteConfigProviderSharedPtr> a list of all the
   * RouteConfigProviders currently loaded.
   */
  virtual std::vector<Router::RouteConfigProviderSharedPtr> routeConfigProviders() PURE;

  /**
   * Add a RouteConfigProvider. Ownership of the RouteConfigProvider is shared by all the
   * ConnectionManagers who own a RouteConfigProviderSharedPtr. The HttpRouteManager holds weak_ptrs
   * to the RouteConfigProviders.
   * @param name supplies the name of the RouteConfigProvider. This is a unique identifier.
   * @param routeConfigProvider is a weak_ptr to the RouteConfigProvider to add.
   */
  virtual void
  addRouteConfigProvider(const std::string& name,
                         std::weak_ptr<Router::RouteConfigProvider> routeConfigProvider) PURE;

  /**
   * Get a RouteConfigProviderSharedPtr by name. This function returns a nullptr if a
   * RouteConfigProvider by the supplied name does not exist.
   * @param name supplies the name of the RouteConfigProvider to return.
   * @return Router::RouteConfigProviderSharedPtr of the RouteConfigProvider with the specified
   * name, nullptr if it does not exist.
   */
  virtual Router::RouteConfigProviderSharedPtr getRouteConfigProvider(const std::string& name) PURE;

  /**
   * Remove a RouteConfigProvider by name. This function should be called by the destructor of the
   * RouteConfigProvider.
   * @param name supplies the name of the RouteConfigProvider to delete.
   */
  virtual void removeRouteConfigProvider(const std::string& name) PURE;
};
} // namespace Server
} // namespace Envoy